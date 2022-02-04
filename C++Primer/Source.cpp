#include <string>
#include "Sales_data.h"
#include "vector"
#include "stdexcept"
extern const int b = 2;
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
int size(int(&a)[6])
{
	int b[sizeof(a)/sizeof(*a)];
	return sizeof(b) / sizeof(b);
}

int jieCheng()//6.4
{
	int num,result=1;
	cin >> num;
	while (num > 1)
		result *= num--;
	return result;
}
double absolute(double val)//6.5
{
	/*if (val >= 0)
		return val;
	else
		return -val;*/
	return abs(val);
}
int count()//6.7
{
	static int jj;
	return jj++;
}
void distinguish_variable(int para)//6.6
{
	int instance = 0;
	static int static_variable =9;
	//para和instance每次调用函数时都重新创建，static_variable在函数第一次被调用时被创建，直到程序结束才被销毁
}
int main()
{
	cout << count() << endl;
	cout << count() << endl;
	return 0;
}

