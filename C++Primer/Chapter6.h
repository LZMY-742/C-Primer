#include "string"
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