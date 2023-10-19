#include <iostream>

class A
{
public:

	~A()
	{
		delete this;
		this = nullptr;
	}
};

int main()
{
	A a;
}