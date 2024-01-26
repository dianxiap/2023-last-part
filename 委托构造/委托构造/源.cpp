#include <iostream>
#include <vector>
using namespace std;

class NoDefault
{
public:
	NoDefault(int i) {}
};
class C
{
public:
	C() :def(0) {}
private:
	NoDefault def;
};

int main()
{
	vector<C> c;
	return 0;
}
//#include "7.41.h"
//
//using std::cout; using std::endl;
//
//int main()
//{
//	cout << "1. default way: " << endl;
//	cout << "----------------" << endl;
//	Sales_data s1;
//	//Sales_data s5();
//
//	cout << "\n2. use std::string as parameter: " << endl;
//	cout << "----------------" << endl;
//	Sales_data s2("CPP-Primer-5th");
//
//	cout << "\n3. complete parameters: " << endl;
//	cout << "----------------" << endl;
//	Sales_data s3("CPP-Primer-5th", 3, 25.8);
//
//	cout << "\n4. use istream as parameter: " << endl;
//	cout << "----------------" << endl;
//	Sales_data s4(std::cin);
//
//	return 0;
//}