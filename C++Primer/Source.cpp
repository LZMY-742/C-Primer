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


int main(int argc, char **argv)
{
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				cout << total.bookNo << " " << total.units_sold << " "
					<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue
			<< endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}

