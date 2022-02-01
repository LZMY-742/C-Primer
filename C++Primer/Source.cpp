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
	cout << "请输入被除数和除数：";
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("除数不得为0");//抛出异常后立即开始寻找对应的处理方式，终止try块内接下来的语句
			cout << a / b << endl;
			cout << "请输入被除数和除数：";
		}
		catch (runtime_error err)//err是runtime_error类的一个实例，实例取任何名字都行
		{
			cout << err.what() << endl;
			cout << "Try again? Enter y/n: ";
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
			cout << "请输入被除数和除数：";
		}
	}
	

	return 0;
}

