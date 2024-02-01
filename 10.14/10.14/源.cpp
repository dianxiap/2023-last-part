#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec{ 1, 2,3,4,5,6,7,8,9 };
	vector<int> v1;
	list<int> v2;
	vector<int> v3;
	auto it = v3.begin();

	unique_copy(vec.begin(), vec.end(), back_inserter(v1));
	unique_copy(vec.begin(), vec.end(), front_inserter(v2));
	unique_copy(vec.begin(), vec.end(), inserter(v3,it));

	for (auto i : v1)cout << i << " ";
	cout << endl;
	for (auto i : v2)cout << i << " ";
	cout << endl;
	for (auto i : v3)cout << i << " ";
	cout << endl;
	/*for (auto i : lst)
		std::cout << i << " ";
	std::cout << std::endl;*/
	/*int i = 10;
	auto f = [&i]()->bool {return i == 0 ? true : !(i--); };
	while (!f())
	{
		cout << i << endl;
	}*/
}