#ifndef SALES_DATA
#define SALES_DATA
#include <string>
#include <iostream>
using std::string;
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
#endif