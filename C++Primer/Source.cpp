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
		test.push_back(word);//����һ�����е��ַ���
	for (auto iter=test.begin()+1;iter!=test.end();++iter)//�ӵڶ���Ԫ�ر����ַ�������
	{
		if (*iter == *(iter - 1))//�������е�ǰ�ַ�������һ���ַ����Ƚ�
		{
			if (isupper((*iter)[0]))//�����ظ����ֵĴ�ʱ��д��ĸ��ͷ���˳�ѭ��
			{
				reWord = *iter;
				break;//�����ͬ�˳�ѭ��
			}
			else//��֮����ѭ��
				continue;//��ʵû�����continueҲ��һ����Ч��
		}
	}
	if (!reWord.empty())//���reWord���ǿյģ�˵��������ֵ���������ظ��Ĵ�
		cout << reWord << "�ظ���" << endl;
	else//���reWord�ǿյģ�˵��û������ֵ��Ҳ����û�������ظ��Ĵ�
		cout << "û�д��������ֹ�" << endl;
	return 0;
	
}

