#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
	
	~A()
	{
		cout << "~A()" << endl;
	}
	A(const A&& a)
	{
		cout << "A(const A&&a)" << endl;
	}
};

A test()
{
	A a;
	return a;
}

int main()
{
	A ret(test());
	return 0;
}