#define _CRT_SECURE_NO_WARNINGS 1
#include "unordered_map.h"
#include "unordered_set.h"
#include <iostream>
using namespace std;

void test_unordered01()
{
	unordered_map<int, int> mp1;
	mp1.insert({ 1,1 });
	mp1.insert({ 54,54 });
	mp1.insert({ 2,2 });
	mp1.insert({ 3,3 });
	mp1.insert({ 4,4 });
	mp1.insert({ 6,6 });
	mp1.insert({ 6,6 });
	mp1.print();
	cout << "Erase:---------------" << endl;
	mp1.erase(1);
	mp1.erase(54);
	mp1.print();

	cout << endl << "--------------------------------------" << endl;
	unordered_set<int> st1;
	st1.insert(1);
	st1.insert(54);
	st1.insert(2);
	st1.insert(3);
	st1.insert(4);
	st1.insert(6);
	st1.insert(6);
	st1.print();
	cout << "Erase:---------------" << endl;
	st1.erase(1);
	st1.erase(54);
	st1.print();
}

void test_iterator01()
{
	unordered_map<string, string> dict;
	dict.insert({ "sort","ÅÅĞò" });
	dict.insert({ "left","×ó±ß" });
	dict.insert({ "right","ÓÒ±ß" });
	dict.insert({ "string","×Ö·û´®" });
	unordered_map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << " : " << it->second << endl;
		++it;
	}
	cout << endl;
}


void test_iterator02()
{
	unordered_map<string, int> countMap;
	string arr[] = { "Æ»¹û","Î÷¹Ï","²¤ÂÜ","²İİ®","²¤ÂÜ","²İİ®" ,"²¤ÂÜ","²İİ®"
			, "Î÷¹Ï", "²¤ÂÜ", "²İİ®", "Î÷¹Ï", "²¤ÂÜ", "²İİ®","Æ»¹û" };
	for (auto e : arr)
	{
		countMap[e]++;
	}
	for (auto kv : countMap)
	{
		cout << kv.first << " " << kv.second << endl;
	}
}
int main()
{
	test_iterator02();
}