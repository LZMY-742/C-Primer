#ifndef SALES_DATA
#define SALES_DATA
#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;
struct Sales_data
{
	double revenue=0;
	unsigned units_sold=0;
	string bookNo="";//类内初始值

	Sales_data() = default;
	
	Sales_data(string s, unsigned u, double r) : bookNo(s), units_sold(u),
		revenue(r) {}
	Sales_data(string s) :bookNo(s) {}

	Sales_data& combine(const Sales_data& rhs)
	{
		revenue += rhs.revenue;
		units_sold += rhs.units_sold;
		return *this;
	}
	string isbn();
	Sales_data(istream& is);
	istream& read(istream& is);
};
string Sales_data::isbn()
{
	return bookNo;
}
Sales_data::Sales_data(istream& is)
{
	read(is);
}
istream& Sales_data::read(istream& is)
{
	double price = 0;
	is >> bookNo >> units_sold >> price;
	revenue = price * units_sold;
	return is;
}
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data a, const Sales_data b);
struct Person
{
	string name;
	string address;
	string get_name() const//应该使用const因为函数没有改变内部变量
	{
		return name;
	}
	string get_address() const//应该使用const因为函数没有改变内部变量
	{
		return address;
	}
};
istream& read_person(istream& is, Person& Amanda);
ostream& print_person(ostream& os, const Person& Amanda);
#endif