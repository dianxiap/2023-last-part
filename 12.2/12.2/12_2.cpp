#include "12_2.h"
#include <iostream>

int main()
{
	StrBlob sb{ "hello","world" };
	const StrBlob csb{ "const","hello","world","aaa" };
	std::cout << "sb:" << sb.front() << " " << sb.back() << std::endl;
	std::cout << "csb:" << csb.front() << " " << csb.back() << std::endl;
	
}