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
//		cout<<e<<" "��
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
//		//���캯��
//		string(const char* str = "")
//		{
//			cout << "string(const char* str) -- ���캯��" << endl;
//
//			_size = strlen(str); //��ʼʱ���ַ�����С����Ϊ�ַ�������
//			_capacity = _size; //��ʼʱ���ַ�����������Ϊ�ַ�������
//			_str = new char[_capacity + 1]; //Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��
//			strcpy(_str, str); //��C�ַ����������ѿ��õĿռ�
//		}
//		//�����������������
//		void swap(string& s)
//		{
//			//���ÿ����swap
//			::swap(_str, s._str); //�������������C�ַ���
//			::swap(_size, s._size); //������������Ĵ�С
//			::swap(_capacity, s._capacity); //�����������������
//		}
//		//�������캯�����ִ�д����
//		string(const string& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(const string& s) -- ��������" << endl;
//
//			string tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
//			swap(tmp); //��������������
//		}
//		//�ƶ�����
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//			swap(s);
//		}
//		//������ֵ�������ִ�д����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(const string& s) -- ���" << endl;
//
//			string tmp(s); //��s�������������tmp
//			swap(tmp); //��������������
//			return *this; //������ֵ��֧��������ֵ��
//		}
//		//�ƶ���ֵ
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
//			swap(s);
//			return *this;
//		}
//		//��������
//		~string()
//		{
//			//delete[] _str;  //�ͷ�_strָ��Ŀռ�
//			_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
//			_size = 0;      //��С��0
//			_capacity = 0;  //������0
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
//	mylist.push_back(kv);                              //����ֵ
//	cout << endl;
//	mylist.push_back(pair<int, cl::string>(2, "two")); //����ֵ
//	cout << endl;
//	mylist.push_back({ 3, "three" });                  //�б��ʼ��
//	return 0;
//}

//struct Goods
//{
//	string _name;  //����
//	double _price; //�۸�
//	int _num;      //����
//};
//
//int main()
//{
//	vector<Goods> v= { { "ƻ��", 2.1, 300 }, { "�㽶", 3.3, 100 }, { "����", 2.2, 1000 }, { "����", 1.5, 1 } };
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

