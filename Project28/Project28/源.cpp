#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

//int sum(const initializer_list<int> &a)
//{
//	int sum = 0;
//	for (auto t : a)
//		sum += t;
//	return sum;
//}

string (&func(int))[10]
{

}
//类型别名
typedef string str[10];
str& func();

//尾置
auto func()->string(&)[10];

//decltype关键字
string s[10];
decltype(s)& func();

int calc(int, int);
int calc(const int, const int);

int main()
{
	calc(10, 20);
	const int a = 10;

	//int const  &i = a;
	 //int& j = a;
	//i = 20;
	//j = 20;


	return 0;
}

//int main(int argc, char* argv[])
//{
//	string str;
//	for (int i = 1; i != argc; i++)
//	{
//		str += string(argv[i]) + " ";
//	}
//	cout << str;
//}