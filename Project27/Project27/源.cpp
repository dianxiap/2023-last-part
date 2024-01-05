#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	int a, b;
	cout << "Please enter two numbers:> " << endl;
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("divisor is 0") ;
			cout << a / b << endl;
		}
		catch(runtime_error err)
		{
			cout << err.what() << "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (c != 'y')break;
		}
		cout << "Please enter two numbers:> " << endl;

	}

	return 0;
}