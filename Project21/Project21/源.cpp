#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i = 42;
	const int& r = 42;
	const int& r2 = r + i;
	
	/*double p = 1.6;
	const int& j = p;*/

	string p1 = "1235";
	string p2 = "2345";
	if (p1 < p2)cout << "1" << endl;
	else cout << "2" << endl;

	int* p = new int[10]();
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << endl;
	}

}