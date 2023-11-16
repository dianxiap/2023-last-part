#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
	Stack(int capacity =10,string name="name")
		:_size(0)
		,_capacity(capacity)
		,_data(new int[capacity])
		, _name(name)
	{}
	
	//获取元素个数
	int size()
	{
		return _size;
	}
	void push(int x)
	{
		if (_size == _capacity)
		{
			int* newdata = new int[_capacity * 2];
			for (int i = 0; i < _size; i++)
			{
				newdata[i] = _data[i];
			}
			free(_data);
			_data = newdata;
			_capacity *= 2;
		}
		_data[_size++] = x;
	}
	//返回栈顶元素
	int top()
	{
		return _data[_size - 1];
	}
	void pop()
	{
		if (_size == 0)return;
		_size--;

	}
	//判空
	bool empty()
	{
		return _size == 0;
	}
	string name() {
		return _name;
	}
	void hanoi(int n, Stack& from_rod, Stack& to_rod, Stack& aux_rod) {
		if (n == 1) {
			int disk = from_rod.top();
			from_rod.pop();
			to_rod.push(disk);
			cout << "移动盘子 " << disk << " 从柱子 " << from_rod.name() << " 到柱子 " << to_rod.name() << endl;
			return;
		}

		// 将 n-1 个盘子从 from_rod 移动到 aux_rod
		hanoi(n - 1, from_rod, aux_rod, to_rod);

		// 移动第 n 个盘子从 from_rod 到 to_rod
		int disk = from_rod.top();
		from_rod.pop();
		to_rod.push(disk);
		cout << "移动盘子 " << disk << " 从柱子 " << from_rod.name() << " 到柱子 " << to_rod.name() << endl;

		// 将 n-1 个盘子从 aux_rod 移动到 to_rod
		hanoi(n - 1, aux_rod, to_rod, from_rod);
	}
private:
	int _size;
	int _capacity;
	int* _data;
	string _name;
};


int main()
{
	Stack A(3, "A");
	Stack B(3, "B");
	Stack C(3, "C");
	A.push(3);
	A.push(2);
	A.push(1);
	A.push(4);
	A.hanoi(4, A, B, C);
	return 0;

}