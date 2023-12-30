#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
	/*const string s="Keep out!";
	for (auto& c : s)
	{
		cout<<typeid(c).name();
	*///}
	//vector<string> v{10,"hi"};
	//vector<int> v1;
	////v1[0] = 42;
	////cout << v[0];
	//string s;
	//s[0] = 0;
	//cout << s << endl;

	int cnt = 42;
	const int sz = 42;
	int a[sz];
	constexpr int p = 42;
	int b[p];
	string s = "11";
	int arr[3][4] = { 0,1,2,3,4,5,6 };
	for (auto row : arr)
	{
		for (auto col : row)
			cout << col;
	}

}