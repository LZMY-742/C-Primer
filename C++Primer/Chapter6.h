#include "string"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#pragma once
int jieCheng();//6.4
double absolute(double val);//6.5
void distinguish_variable(int para);//6.6
int count();//6.7
inline bool isShorter(const string& s1, const string& s2)//6.44
{
	return s1.size() < s2.size();
}
inline void f()
{
	cout << "void" << endl;
}
inline void f(int)
{
	cout << "int" << endl;
}
inline void f(int, int)
{
	cout << "int,int" << endl;
}
inline void f(double, double = 3.14)
{
	cout << "double,double=3.14" << endl;
}