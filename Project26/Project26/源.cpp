#include <iostream>
#include <vector>
using namespace std;

int next_num()
{
	return 3;
}

int main()
{
	/*string s;
	vector<string> v;
	while (cin >> s)
	{
		v.push_back(s);
	}
	auto it = v.begin();
	int cnt = 0;
	string tmp = *it;
	string res;
	int maxv = 0;
	while (it != v.end())
	{
		if (tmp == *it)
		{
			cnt++;
			it++;
		}
		else
		{
			tmp = *it;
			cnt = 1;
			it++;
		}
		if (maxv < cnt)
		{
			maxv = cnt;
			res = tmp;
		}
	}
	cout << res << " " << maxv;*/
	vector<int> v1{ 0,1,1,2 };
	vector<int> v2{ 0,1,1,2,3,5,4 };
	
	for (int i=0,j=0;j<v2.size();j++)
	{
		if (v2[j] == v1[i])
		{
			i++;
		}
		else
		{

		}
	}
}