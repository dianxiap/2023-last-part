#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>

using namespace std;


//template<class T,class ...Args>
//void ShowList(T value,Args... args)
//{
//	cout << value << endl;
//	if (sizeof...(args) == 0)
//		return;
//	ShowList(args...);
//}

//template< class ...Args>
//void ShowList( Args... args)
//{
//	int arr[] = { args... };
//	for (auto e : arr)
//	{
//		cout<<e<<" "；
//	}
//	cout << endl;
//}

//void Showlist()
//{
//	cout << endl;
//}
//
//template<class T>
//int PrintArg(const T& t)
//{
//	cout << t << " ";
//	return 0;
//}
//
//template<class ...Args>
//void Showlist(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}

//namespace cl
//{
//	class string
//	{
//	public:
//		//构造函数
//		string(const char* str = "")
//		{
//			cout << "string(const char* str) -- 构造函数" << endl;
//
//			_size = strlen(str); //初始时，字符串大小设置为字符串长度
//			_capacity = _size; //初始时，字符串容量设置为字符串长度
//			_str = new char[_capacity + 1]; //为存储字符串开辟空间（多开一个用于存放'\0'）
//			strcpy(_str, str); //将C字符串拷贝到已开好的空间
//		}
//		//交换两个对象的数据
//		void swap(string& s)
//		{
//			//调用库里的swap
//			::swap(_str, s._str); //交换两个对象的C字符串
//			::swap(_size, s._size); //交换两个对象的大小
//			::swap(_capacity, s._capacity); //交换两个对象的容量
//		}
//		//拷贝构造函数（现代写法）
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(const string& s) -- 拷贝构造" << endl;
//
//			string tmp(s._str); //调用构造函数，构造出一个C字符串为s._str的对象
//			swap(tmp); //交换这两个对象
//		}
//		//移动构造
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 移动构造" << endl;
//			swap(s);
//		}
//		//拷贝赋值函数（现代写法）
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- 深拷贝" << endl;
//
//			string tmp(s); //用s拷贝构造出对象tmp
//			swap(tmp); //交换这两个对象
//			return *this; //返回左值（支持连续赋值）
//		}
//		//移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//			swap(s);
//			return *this;
//		}
//		//析构函数
//		~string()
//		{
//			//delete[] _str;  //释放_str指向的空间
//			_str = nullptr; //及时置空，防止非法访问
//			_size = 0;      //大小置0
//			_capacity = 0;  //容量置0
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity;
//	};
//}

//int main()
//{
//	Showlist();
//	Showlist(1);
//	Showlist(1,2);
//	Showlist(1,2,3);
//
//}
//int main()
//{
//	list<pair<int, cl::string>> mylist;
//
//	pair<int, cl::string> kv(1, "one");
//	cout << endl;
//	cout << endl;
//	mylist.push_back(kv);                              //传左值
//	cout << endl;
//	mylist.push_back(pair<int, cl::string>(2, "two")); //传右值
//	cout << endl;
//	mylist.push_back({ 3, "three" });                  //列表初始化
//	return 0;
//}

//struct Goods
//{
//	string _name;  //名字
//	double _price; //价格
//	int _num;      //数量
//};
//
//int main()
//{
//	vector<Goods> v= { { "苹果", 2.1, 300 }, { "香蕉", 3.3, 100 }, { "橙子", 2.2, 1000 }, { "菠萝", 1.5, 1 } };
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price < g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price < g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price < g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)
//		{
//			return g1._price < g2._price;
//		});
//
//}

//int main()
//{
//	int a = 10, b = 20;
//	auto Swap = [&a,&b]
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//	Swap();
//	cout << a << ' ' << b << endl;
//	return 0;
//}

//class Add
//{
//public:
//	Add(int base)
//		:_base(base)
//	{
//
//	}
//	int operator()(int num)
//	{
//		return _base + num;
//	}
//private:
//	int _base;
//};
//
//int main()
//{
//	int a = 10, b = 20;
//	auto Swap1 = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	auto Swap2 = [](int& x, int& y)->void
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	cout << typeid(Swap1).name() << endl; //class <lambda_797a0f7342ee38a60521450c0863d41f>
//	cout << typeid(Swap2).name() << endl; //class <lambda_f7574cd5b805c37a13a7dc214d824b1f>
//	return 0;
//}

//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator()(int a,int b)
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//
//	function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//
//	function<int(int, int)> func3 = [](int a, int b) {return a + b; };
//	cout << func3(1, 2) << endl;
//
//	function<int(int, int)> func4 = Plus::plusi;
//	cout << func4(1, 2) << endl;
//
//	function<double(Plus,double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//
//}


template<class F,class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}

double f(double i)
{
	return i/2;
}

struct Functor
{
	double operator()(double d)
	{
		return d / 2;
	}
};

int main()
{
	function<double(double)>func1 = f;
	cout << useF(func1, 11.11) << endl;

	function<double(double)>func2 = Functor();
	cout << useF(func2, 11.11) << endl;

	function<double(double)>func3 = [](double d)->double {return d / 4; };;
	cout << useF(func3, 11.11) << endl;


}

