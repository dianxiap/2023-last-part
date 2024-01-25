#ifndef __PERSON__
#define __PERSON__

#include <iostream>
#include <string>

//class Person
//{
//	friend std::istream& read(std::istream& is, Person&);
//	friend std::ostream& print(std::ostream& os, Person&);
//class:
//	Person() = default;
//	Person(const std::string& sname, const std::string& saddr)
//		:name(sname), address(saddr)
//	{}
//	Person(std::istream& is) { read(is, *this); }
//
//	std::string getname()const { return name; }
//	std::string getaddr()const { return addr; }
//private:
//	std::string name;
//	std::string address;
//};
//
//std::istream& read(std::istream& is, Person& p)
//{
//	is >> p.name >> p.address;
//	return is;
//}
//std::ostream& print(std::ostream& os, Person& p)
//{
//	os << p.name << p.address;
//	return os;
//}


class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht* wd, ' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}

	char get()const { return contents[cursor]; }
	char get(pos r, pos c)const { return contents[r * width + c]; }

	inline Screen& move(pos r, pos c);
	inline Screen& set(char c);
	inline Screen& set(pos r, pos c, char ch);

	const Screen& display(std::ostream& os)const { do_display(os); return *this; }
	Screen& display(std::ostream& os) { do_display(os); return *this; }

private:
	void do_display(std::ostream& os)const { os << contents; }
private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
};
inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}

#endif // !__PERSON__
