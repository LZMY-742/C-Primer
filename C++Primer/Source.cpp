
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
#include <list>
#include <deque>
#include <array>
#include <forward_list>
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
using std::list;
using std::deque;
using std::array;
using std::forward_list;

vector<double> Account::vec(vecSize);
double Account::interestRate = 0.2;
istream& read(istream& is, Sales_data& a)
{
	double price = 0;
	is >> a.bookNo >> a.units_sold >> price;
	a.revenue = price * a.units_sold;
	return is;
}
ostream& print(ostream& os, const Sales_data& b)
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
		while (in >> line)
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
vector<int>::iterator& search(vector<int>::iterator& b, vector<int>::iterator& e, int num)//9.5
{
	while (b != e)
	{
		if (*b == num)
			return b;
		++b;
	}
	return e;//没找到就返回最后一个迭代器，注意如果直接解引用尾迭代器会报错
}
forward_list<string>& insert(forward_list<string>& stringList, const string& find, const string& word)//9.28
{
	bool flag = false;
	auto itr = stringList.cbegin(), before_itr = stringList.cbegin();
	for (; itr != stringList.end(); before_itr = itr++)
	{
		if (*itr == find)
		{
			itr = stringList.insert_after(itr, word);
			++flag;
		}
	}
	if (!flag)
	{
		stringList.insert_after(before_itr, word);
	}
	return stringList;
}
void replace(string& s, const string& oldVal, const string& newVal)//9.44
{
	for (decltype(s.size()) i = 0; i != s.size(); ++i)
	{
		if (s[i] == oldVal[0])
		{
			auto ini = i;
			string temp = "";
			while (i != s.size() && i != ini + oldVal.size())
			{
				temp += s[i];
				++i;
			}
			if (temp == oldVal)
			{
				s.replace(ini, oldVal.size(), newVal);
				i = ini + newVal.size() - 1;
			}
			else
			{
				--i;
			}

		}
	}
}
void replace2(string& s, const string& oldVal, string& newVal)//9.43
{
	int _size = oldVal.size();
	int _size1 = newVal.size();
	string::iterator it1 = s.begin();
	string::iterator it2 = newVal.begin();
	string::iterator it3 = newVal.end();

	for (it1; it1 <= (s.end() - oldVal.size() + 1); ++it1)
	{
		//pos可以由两个迭代器相减得到,返回截取到的string  
		if ((s.substr(it1 - s.begin(), _size) == oldVal))//substr()的作用就是截取string中的一段  
		{
			it1 = s.erase(it1, it1 + _size);//返回的是最后一个被删除的元素之后的位置  
			it1 = s.insert(it1, it2, it3);//原因在于insert()函数返回了指向第一个插入字符的迭代器，而我将其直接赋值给it1，从const转为非const，类型不同，产生错误  

			advance(it1, _size1 - 1);//向前_size1-1大小，目的是为了让it1仍然指向当前字符串的首位置，因为前面进行了++it1
		}
	}
}

int main(int argc, char** argv)
{
	string s = "ddd thruxixi", old = "thru", newVal = "through";
	replace2(s, old, newVal);
	cout << s << endl;
	return 0;
}

