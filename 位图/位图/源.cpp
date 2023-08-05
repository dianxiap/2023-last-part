#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>
using namespace std;

const int N = 1000;
template<size_t N>
class bit_set
{
public:
	//构造函数
	bit_set()
	{
		_bits.resize(N / 8 + 1, 0);
	}

	//将映射的地方改为1
	void set(size_t x)
	{
		size_t i = x / 8;	//求在第几个char处
		size_t j = x % 8;	//求在第几位上

		_bits[i] |= (1 << j);
	}

	//删除这个数据
	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] &= ~(1 << j);	//左移取反再 与
	}

	//判断x在不在
	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		return _bits[i] & (1 << j);
	}
private:
	vector<char> _bits;
};