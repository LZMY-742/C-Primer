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
	auto itr = wordList.begin() + 1, maxItr = wordList.begin();//���ַ��������ĵڶ����ַ���ǰ����
	while (itr != wordList.end())
	{
		word = *itr;
		preWord = *(itr - 1);
		if (word == preWord)//���ǰһ���ʺͺ�һ����һ�������ʵļ���+1
		{
			++nowRepeat;
			if (nowRepeat > maxRepeat)//�����������ʵļ�����֮ǰ���ļ�����Ļ�
			{
				maxRepeat = nowRepeat;//����������Ϊ��������ʵļ���
				maxItr = itr;//��¼����ָ������ظ������ĵ���
			}
		}
		else
		{
			nowRepeat = 1;//���ǰ�������ʲ�һ�£��ʵļ�����Ϊ1
		}
		++itr;
	}
	if (maxRepeat == 1)
		cout << "û�е����������ֹ�" << endl;
	else
		cout << "���ʣ�" << *maxItr << "�����ˣ�" << maxRepeat << "��";
	return 0;
}

