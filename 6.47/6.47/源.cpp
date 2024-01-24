#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Person
{
public:
	string name;
	string address;

	auto getname()const->string const&
	{
		return name;
	}
	string getaddress()const
	{
		return address;
	}
};

istream& read(istream& is, Person& p)
{
	return is >> p.name >> p.address;
}
ostream& print(ostream& os, const Person& p)
{
	return os << p.name << " " << p.address;
}

//using namespace std;
//
//int add(int a, int b) { return a + b; }
//int sub(int a, int b) { return a - b; }
//int mul(int a, int b) { return a * b; }
//int di(int a, int b) { return b!=0?a / b:0; }
//
//int main()
//{
//	int func(int, int);
//	vector<decltype(func)*> v;
//	v.push_back(add);
//	v.push_back(sub);
//	v.push_back(mul);
//	v.push_back(di);
//	for (auto i : v)
//	{
//		cout << i(6, 2) << " ";
//	}
//}
//
//using Iter = vector<int>::const_iterator;
//
//#define NDEBUG
//
//void print(Iter first, Iter last)
//{
//#ifndef NDEBUG
//	cout << "vector size: " << last - first << endl;
//#endif
//	if (first == last)
//	{
//		cout << "over!" << endl;
//		return;
//	}
//	cout << *first << " ";
//	print(++first, last);
//
//}
//int f(int, int)
//{
//	cout << "f1" << endl;
//}
//int f(double, double)
//{
//	cout << "f2" << endl;
//}

//void manip(long);
//void manip(float);
//int main()
//{
//	//manip(3.14);
//
//	return 0;
//}