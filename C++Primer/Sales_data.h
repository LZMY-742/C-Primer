#ifndef SALES_DATA
#define SALES_DATA
#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;
struct Sales_data
{
	double revenue;
	unsigned units_sold;
	string bookNo;
	Sales_data& combine(const Sales_data& rhs)
	{
		revenue += rhs.revenue;
		units_sold += rhs.units_sold;
		return *this;
	}
	string isbn();
};
string Sales_data::isbn()
{
	return bookNo;
}
istream& read(istream& is, Sales_data& item);
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data a, const Sales_data b);
struct Person
{
	string name;
	string address;
	string get_name() const//Ӧ��ʹ��const��Ϊ����û�иı��ڲ�����
	{
		return name;
	}
	string get_address() const//Ӧ��ʹ��const��Ϊ����û�иı��ڲ�����
	{
		return address;
	}
};
#endif