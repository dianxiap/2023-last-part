#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void f(int arg)
{
	cout << "void f(int arg)" << endl;
}
void f(int* arg)
{
	cout << "void f(int* arg)" << endl;
}
int main()
{
	f(NULL);    //void f(int arg)
	f(nullptr); //void f(int* arg)
	return 0;
}
