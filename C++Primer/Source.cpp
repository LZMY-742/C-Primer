#include <string>
#include "Sales_data.h"
#include "vector"
//#include "iterator"

//#include "cctype"
extern const int b = 2;
void increment(int i);
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::strcat;
int size(int(&a)[6])
{
	int b[sizeof(a)/sizeof(*a)];
	return sizeof(b) / sizeof(b);
}
int main()
{
	vector<int> My_vec1{ 0,1,2,3,4 };
	vector<int> My_vec2{ 0,1,2,3,4,5 };
	int small_size = My_vec1.size() > My_vec2.size() ? My_vec2.size() : My_vec1.size();//挑出较小者
	for (int i = 0; i < small_size; i++)
	{
		if (My_vec1[i] != My_vec2[i])
		{
			cout << "False" << endl;
			return 0;//如有不匹配的元素即输出False结束
		}
	}
	cout << "True" << endl;
	return 0;//如果用void main(),可以用一个flag来表示是否每个元素都相等
	
}

