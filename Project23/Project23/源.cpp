#include <iostream>

using namespace std;

int tmp = 10;

int main()
{
	
	double dval = 3.14;
	const int& ri = dval;

	int i = 42;
	int& r1 = i;
	const int& r2 = i;
	r1 = 0;
	cout << r2 << endl;
}