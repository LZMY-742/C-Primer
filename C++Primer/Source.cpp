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
	/*Sales_data total;
	if (read(cin,total)) {
		Sales_data trans;
		while (read(cin,trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total);
				total = trans;
			}
		}
		print(cout , total);
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}*/
	Sales_data jj("zhubi",3,4);
	Sales_data ff;
	Sales_data cc(cin);
	print(cout, jj);
	print(cout, ff);
	print(cout, cc);
	return 0;
}

