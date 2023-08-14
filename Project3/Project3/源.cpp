#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v1{ 10,20,30 };
	vector<int> v2{ 1,2,3 };
	swap(v1, v2);
	auto it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;
	auto it2 = v2.begin();
	while (it2 != v2.end())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
	v1.swap(v2);
	auto it3 = v1.begin();
	while (it3 != v1.end())
	{
		cout << *it3 << " ";
		it3++;
	}
	cout << endl;
	auto it4 = v2.begin();
	while (it4 != v2.end())
	{
		cout << *it4 << " ";
		it4++;
	}
}
//class A
//{
//public:
//	A(int a,int b)
//		:_a(a)
//		,_b(b)
//	{}
//	~A()
//	{}
//private:
//	int _a = 0;
//	int _b = 0;
//};
//
//int main()
//{
//	A aa(10, 20);
//	A bb(1, 2);
//	swap(aa, bb);
//
//}