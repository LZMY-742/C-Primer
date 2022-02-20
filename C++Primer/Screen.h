#pragma
#include "string"
#include <iostream>
using std::string;
class Screen;
class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(Screen&);
	Window_mgr() = default;
private:
	//std::vector<Screen> screens{ Screen(24,80,' ') };
};
class Screen {
	friend void Window_mgr::clear(Screen& s);
public:

	typedef string::size_type pos;
	Screen() = default;
	Screen(pos h, pos w,char c) :height(h), width(w), contents(h* w, c) {}
	Screen(pos h, pos w): height(h),width(w),contents(h*w,' '){}//7.24

	Screen& set(char c);
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
	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const//根据调用对象是否是const判断调用哪个函数
	{
		do_display(os);
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(std::ostream& os) const
	{
		os << contents<<endl;
	}
};

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

void Window_mgr::clear(Screen& s)
{
	s.contents = std::string(s.height*s.width, ' ');
}