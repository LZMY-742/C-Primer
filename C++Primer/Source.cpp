#include <string>
#include "Sales_data.h"
#include "vector"
#include "stdexcept"
#include"cstdlib"
#include "Chapter6.h"
//#define NDEBUG
#include "cassert"


using std::cout;
using std::cin;
using std::endl;
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

istream& read(istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
ostream& print(ostream& os, const Sales_data& item)
{
	os << "revenue: " << item.revenue << endl << "units_sold: " << item.units_sold << endl
		<< "bookNo: " << item.bookNo << endl;
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
	Sales_data total(cin);
	if (cin)
	{
		Sales_data trans(cin);
		do
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		} while (read(cin, trans));
		print(cout, total) << endl;
	}
	else
	{
		std::cerr << "No data?!" << endl;
	}
	return 0;
}

