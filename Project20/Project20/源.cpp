#include <iostream>
using namespace std;

class Queue
{
public:
	Queue(int capacity = 10)
		:_head(0)
		, _tail(0)
		, _size(0)
		,_capacity(capacity)
		,_data(new int[capacity])
	{}
	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}
	void push(int x)
	{
		if (_size == _capacity)
		{
			int* tmp = new int[_capacity * 2];
			for (int i = 0; i < _capacity; i++)
			{
				tmp[i] = _data[(_head+i)%_capacity];
			}
			delete[] _data;
			_data = tmp;
			_capacity *= 2;
			_head = 0;
			_tail = _size;
		}
		_data[_tail] = x;
		_tail = (_tail + 1) % _capacity;
		_size++;
	}
	int front()
	{
		return _data[_head];
	}
	void pop()
	{
		if (_size == 0)return;
		_head = (_head + 1) % _capacity;
		--_size;
	}
	~Queue()
	{
		delete[] _data;
	}
private:
	int _head;
	int _tail;
	int _size;
	int _capacity;
	int* _data;
};

int main()
{
	Queue q(3);
	q.push(1);
	q.push(8);
	q.push(3);
	q.push(-3);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}

}