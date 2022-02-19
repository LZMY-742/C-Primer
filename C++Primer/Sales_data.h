#ifndef SALES_DATA
#define SALES_DATA
#include <string>
#include <iostream>
using std::string;
using std::istream;
using std::ostream;
using std::endl;
class Sales_data
{
private:
	double revenue=0;
	unsigned units_sold=0;
	string bookNo="";//类内初始值
	double avg_price();
public:
	Sales_data() = default;
	
	Sales_data(string s, unsigned u, double r) : bookNo(s), units_sold(u),
		revenue(r) {}
	Sales_data(string s) :bookNo(s) {}
	Sales_data(istream& is)
	{
		read(is);
	}

	Sales_data& combine(const Sales_data& rhs)
	{
		revenue += rhs.revenue;
		units_sold += rhs.units_sold;
		return *this;
	}
	string isbn()
	{
		return bookNo;
	}
	istream& read(istream& is)
	{
		double price = 0;
		is >> bookNo >> units_sold >> price;
		revenue = price * units_sold;
		return is;
	}
	ostream& print(ostream& os)
	{
		os << "revenue: " << revenue << endl << "units_sold: " << units_sold << endl
			<< "bookNo: " << bookNo << endl;
		return os;
	}
	
};

Sales_data add(const Sales_data a, const Sales_data b);
inline double Sales_data::avg_price()//7.26
{
	return units_sold ? revenue / units_sold : 0;
}



struct Person
{
	friend istream& read_person(istream& is, Person& Amanda);
	friend ostream& print_person(ostream& os, const Person& Amanda);
private:
	string name="";
	string address="";
	
public:
	Person(string n, string a) :name(n), address(a) {}
	Person() = default;

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