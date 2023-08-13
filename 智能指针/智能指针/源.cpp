#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//	{
//		throw invalid_argument("除0错误");
//	}
//	return a / b;
//}
//
//void func()
//{
//	int* p1 = new int;
//	int* p2 = new int;
//	cout << div()<< endl;
//	delete p1;
//	delete p2;
//	cout << "p1,p2释放" << endl;
//}
//
//int main()
//{
//	try
//	{
//		func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//template<class T>
//class SmaartPtr
//{
//public:
//	SmaartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~SmaartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete _ptr;
//	}
//	T& operator*() 
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//	{
//		throw invalid_argument("除0错误");
//	}
//	return a / b;
//}

//void func()
//{
//	SmaartPtr<int> p1 = new int;
//	SmaartPtr<int> p2 = new int;
//	cout << div()<< endl;
//	
//	//cout << "p1,p2释放" << endl;
//}

/*lass A
{
	A()
		:_ptr(nullptr)
	{}
	~A()
	{
		delete _ptr;
	}
private:
	int* _ptr;
};

void test()
{
	auto_ptr<A> p1(new A);
	auto_ptr<A> p2(p1);

}
int main()
{
	test();
}


*/
//namespace dianxia
//{
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		~unique_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _pte << endl;
//				delete _ptr;
//				_ptr = nullptr;
//			}
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		unique_ptr(unique_ptr<T>& up) = delete;
//		unique_ptr& operator=(unique_ptr<T>& up) = delete;
//	private:
//		T* _ptr;
//	};
//}
//

//namespace dianxia
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			, _pcount(new int(1))
//		{}
//		~shared_ptr()
//		{
//			//引用计数为0了
//			if (--(*_pcount) == 0)
//			{
//				if (_ptr!=nullptr)
//				{
//					cout << "delete:" << _ptr << endl;
//					delete _ptr;
//					_ptr = nullptr;
//				}
//				delete _pcount;
//				_pcount = nullptr;
//			}
//		}
//		
//		
//		shared_ptr(shared_ptr<T>& sp)
//			:_ptr(sp._ptr)
//			, _pcount(sp._pcount)
//		{
//			(*_pcount)++;
//		}
//		
//		shared_ptr& operator=(shared_ptr<T>& sp)
//		{
//			//已经管理着同一块空间就不赋值了
//			if (_ptr != sp._ptr)
//			{
//				//将现在管理的资源对应的引用计数--
//				//因为马上要管理新的了
//				if (--(*_pcount) == 0)
//				{
//					cout << "delete:" << _ptr << endl;
//					delete _ptr;
//					delete _pcount;
//				}
//				_ptr = sp._ptr;
//				_pcount = sp._pcount;
//				(*_pcount)++;
//			}
//			return *this;
//		}
//		int use_count()
//		{
//			return *_pcount;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//		int* _pcount;
//	};
//}
//
//int main()
//{
//	dianxia::shared_ptr<int> p1(new int);
//	dianxia::shared_ptr<int> p2(p1);
//	return 0;
//}
//
//
//
//
//
//
//
//
//

struct shard_node
{
	int _val;
	std::shared_ptr<shard_node> _next;
	std::shared_ptr<shard_node> _prev;
	~shard_node()
	{
		cout << "shard_node" << endl;
	}
};

void test()
{
	std::shared_ptr<shard_node> sn1(new shard_node);
	std::shared_ptr<shard_node> sn2(new shard_node);

	sn1->_next = sn2;
	sn2->_prev = sn1;
}

int main()
{
	test();
}

