#include <string>
#include "Sales_data.h"
#include "vector"
#include "stdexcept"
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
using std::runtime_error;
int size(int(&a)[6])
{
	int b[sizeof(a)/sizeof(*a)];
	return sizeof(b) / sizeof(b);
}
int main()
{
	int a,b;
	cout << "�����뱻�����ͳ�����";
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("��������Ϊ0");//�׳��쳣��������ʼѰ�Ҷ�Ӧ�Ĵ���ʽ����ֹtry���ڽ����������
			cout << a / b << endl;
			cout << "�����뱻�����ͳ�����";
		}
		catch (runtime_error err)//err��runtime_error���һ��ʵ����ʵ��ȡ�κ����ֶ���
		{
			cout << err.what() << endl;
			cout << "Try again? Enter y/n: ";
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
			cout << "�����뱻�����ͳ�����";
		}
	}
	

	return 0;
}

