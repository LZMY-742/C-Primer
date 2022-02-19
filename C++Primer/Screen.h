#include "string"
using std::string;
class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(char c, pos h, pos w) :height(h), width(w), contents(h* w, c) {}
	Screen(pos h, pos w): height(h),width(w),contents(h*w,' '){}//7.24
	Screen& move(pos r, pos c)
	{
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
	char get(pos r, pos c) const
	{
		pos row = r * width;
		return contents[row + c];
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};