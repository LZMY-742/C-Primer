#include <string>
#include "Sales_data.h"
#include "vector"
#include "stdexcept"
#include"cstdlib"
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

using arrT = int[10];

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
void exchange(int* ptr1, int* ptr2)//6.10
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
void reset(string& password)//6.11
{
	password = "SB";
}
void exchange2(int& ptr1, int& ptr2)//6.12
{
	int temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;//引用比指针容易，传递参数的时候直接用变量名就行了，使用的时候也不需要不断地用解引用符
}
bool whether_upper(const string& word)//6.17
{
	for (auto c : word)
	{
		if (isupper(c))
			return true;
	}
	return false;
}
void change_to_lower(string& word)//6.17
{
	for (auto& c : word)
	{
		if (isupper(c))
			c = tolower(c);
	}
}
int compare(int a, int *const ptr)//6.21
{
	if (a > *ptr)
	{
		return a;
	}
	else
		return *ptr;
}
void exchange3(int *& ptr1, int*& ptr2)//6.22
{
	auto temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}
void print(int *const p, size_t t)//6.23
{
	for (size_t i = 0; i < t; ++i)
	{
		cout << p[i] << endl;
	}
}
int sum(initializer_list<int> ig)//6.27
{
	int sum = 0;
	for (auto i : ig)
		sum += i;
	return sum;
}
void foo(...)//?
{

}
void print3(vector<int> a,size_t ini)//6.33
{

	if (ini != a.size())
	{
		cout << a[ini] << endl;
		++ini;
		print3(a,ini);
	}


}

int main(int argc, char **argv)
{
	vector<int> list{ 1,2,3,4,5 };
	print3(list,0);
	return EXIT_SUCCESS;
}

