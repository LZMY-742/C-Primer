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
	os << "revenue: " << item.revenue << endl << "units_sold" << item.units_sold << endl
		<< "bookNo: " << item.bookNo << endl;
}
Sales_data add(const Sales_data a, const Sales_data b)
{
	Sales_data c = a;
	c.combine(b);
	return c;
}
int main(int argc, char **argv)
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				cout << total.isbn() << " " << total.units_sold << " "
					<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.isbn() << " " << total.units_sold << " " << total.revenue
			<< endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}

