#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdlib.h>
//#include <stdio.h>
//
//void func(char para[100])
//{
//	void* p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//
//int main()
//{
//	char para[100];
//	func(para);
//}
#include <stdio.h>
void func(char* p) { p = p + 1; }
int main()
{
	char s[] = {'1', '2', '3', '4'};
	func(s);
	printf("%c", *s);
	return 0;
}