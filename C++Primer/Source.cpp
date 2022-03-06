
#include "Sales_data.h"
#include "vector"
#include "stdexcept"
#include"cstdlib"
#include "Chapter6.h"
//#define NDEBUG
#include "cassert"
#include "Screen.h"
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::strcat;
using std::runtime_error;
using std::exception;
using std::initializer_list;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

vector<double> Account::vec(vecSize);
double Account::interestRate = 0.2;
istream& read(istream& is,Sales_data& a )
{
	double price = 0;
	is >> a.bookNo >> a.units_sold >> price;
	a.revenue = price * a.units_sold;
	return is;
}
ostream& print(ostream& os,const Sales_data& b)
{
	os << "revenue: " << b.revenue << endl << "units_sold: " << b.units_sold << endl
		<< "bookNo: " << b.bookNo << endl;
	return os;
}
Sales_data add(const Sales_data a, const Sales_data b)
{
	Sales_data c = a;
	c.combine(b);
	return c;
}
 istream& read_person(istream& is, Person& Amanda)//7.9
{
	is >> Amanda.name >> Amanda.address;
	return is;
}
ostream& print_person(ostream& os, const Person& Amanda)//7.9
{
	os << "Name: " << Amanda.name << endl << "Address: " << Amanda.address;
	return os;
}
int main(int argc, char **argv)
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	Sales_data total;
	if (read(input, total))
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else 
	{
		cerr << "No data?" << endl;
	}
	return 0;
}

