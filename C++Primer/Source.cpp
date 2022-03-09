
#include "Sales_data.h"
#include "vector"
#include "stdexcept"
#include"cstdlib"
#include "Chapter6.h"
//#define NDEBUG
#include "cassert"
#include "Screen.h"
#include <fstream>
#include <sstream>
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
using std::istringstream;
using std::ostringstream;
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
istream& read_file(vector<string>& vec)
{
	ifstream in("input2.txt");
	if (in)
	{
		string line = "";
		while (in>>line)
		{
			vec.push_back(line);
		}
	}
	else
	{
		cerr << "can't open the file!";
	}
	return in;
}
istream& read_string(istream& in)
{
	string word;
	while (in >> word)
		cout << word << endl;
	in.clear();
	return in;
}
void telephone_number(istream& in)
{
	string line, word;
	vector<PersonInfo> people;
	while (getline(in, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for (auto p : people)
		cout << p.name << endl;
}
int main(int argc, char **argv)
{
	ifstream ff("input.txt");
	if (ff)
	{
		telephone_number(ff);
	}
	else
	{
		cerr << "Can't open the file" << endl;
	}
	return 0;
}

