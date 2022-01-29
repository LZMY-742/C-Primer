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
	vector<string> test;
	string word, reWord;
	while (cin >> word)
		test.push_back(word);//输入一个序列的字符串
	for (auto iter=test.begin()+1;iter!=test.end();++iter)//从第二个元素遍历字符串序列
	{
		if (*iter == *(iter - 1))//将序列中当前字符串和上一个字符串比较
		{
			if (isupper((*iter)[0]))//赋过重复出现的词时大写字母开头才退出循环
			{
				reWord = *iter;
				break;//如果相同退出循环
			}
			else//反之继续循环
				continue;//其实没有这句continue也是一样的效果
		}
	}
	if (!reWord.empty())//如果reWord不是空的，说明被赋过值，有连续重复的词
		cout << reWord << "重复了" << endl;
	else//如果reWord是空的，说明没被赋过值，也就是没有连续重复的词
		cout << "没有词连续出现过" << endl;
	return 0;
	
}

