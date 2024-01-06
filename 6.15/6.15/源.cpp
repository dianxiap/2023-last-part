#include <iostream>
using namespace std;

//int add(int &a, int &b)
//{
//	return a + b;
//}

int fun(const int i)
{
	return i;
}
int fun(int i)
{
	return i;
}

int main()
{
	//int i = add(1, 2);
	cout << fun(10);
	return 0;
}