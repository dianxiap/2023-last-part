#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
using namespace std;

double Division(int a, int b)
{
	if (b == 0)
	{
		string s= "Division by zero condition!";
		throw s;
	}
	else
		return (double)a / (double)b;
}

void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}

int  main()
{
	while (1)
	{
		try 
		{
			Func();
		}
		catch (exception p)
		{
			cout << p.what() << endl;
		}
	}
	return 0;
}