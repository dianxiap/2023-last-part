#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>
using namespace std;

const int N = 1000;
template<size_t N>
class bit_set
{
public:
	//���캯��
	bit_set()
	{
		_bits.resize(N / 8 + 1, 0);
	}

	//��ӳ��ĵط���Ϊ1
	void set(size_t x)
	{
		size_t i = x / 8;	//���ڵڼ���char��
		size_t j = x % 8;	//���ڵڼ�λ��

		_bits[i] |= (1 << j);
	}

	//ɾ���������
	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_bits[i] &= ~(1 << j);	//����ȡ���� ��
	}

	//�ж�x�ڲ���
	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		return _bits[i] & (1 << j);
	}
private:
	vector<char> _bits;
};