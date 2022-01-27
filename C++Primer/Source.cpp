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
	vector<string> wordList;
	string word, preWord;
	unsigned preRepeat = 1, nowRepeat = 1, maxRepeat = 1;
	while (cin >> word)
		wordList.push_back(word);
	auto itr = wordList.begin() + 1, maxItr = wordList.begin();//从字符串向量的第二个字符向前检索
	while (itr != wordList.end())
	{
		word = *itr;
		preWord = *(itr - 1);
		if (word == preWord)//如果前一个词和后一个词一样，将词的计数+1
		{
			++nowRepeat;
			if (nowRepeat > maxRepeat)//如果现在这个词的计数比之前最大的计数大的话
			{
				maxRepeat = nowRepeat;//将最大计数变为现在这个词的计数
				maxItr = itr;//记录下来指向最大重复次数的单词
			}
		}
		else
		{
			nowRepeat = 1;//如果前后两个词不一致，词的计数归为1
		}
		++itr;
	}
	if (maxRepeat == 1)
		cout << "没有单词连续出现过" << endl;
	else
		cout << "单词：" << *maxItr << "出现了：" << maxRepeat << "次";
	return 0;
}

