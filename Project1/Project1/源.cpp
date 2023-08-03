#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;
enum State
{
	EMPTY,
	EXIST,
	DELETE
};

template<class T,class V>
struct HashDate
{
	pair<T, V> _kv;
	State _state = EMPTY;
};

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

//string的特化
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t val = 0;
		for (auto ch : key)
		{
			val = val * 131 + ch;
		}
		return val;
	}
};

//Hash仿函数，返回用于成映射哈希表下标的整型值
template<class K,class V,class Hash=HashFunc<K>>
class HashTable
{
public:
	bool Insert(const pair<K, V>& kv)
	{
		//判断表中是否有数据
		if (Find(kv.first))return false;
		//判断负载因子，是否扩容
		if (_table.size() == 0 || 10 * _size / _table.size() >= 7)
		{
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V, Hash> newHash;
			newHash._table.resize(newSize);

			//服用Insert拷贝旧表数据到新表中——可以缓解冲突问题
			for (auto e : _table)
			{
				if (e._state == EXIST)
				{
					newHash.Insert(e._kv);
				}
			}

			//进行交换  newHash自动调用其析构函数
			_table.swap(newHash._table);

		}

		Hash hash;
		size_t hashi = hash(kv.first) % _table.size();

		//如果存在数据就哈希冲突就一直往后找
		while (_table[hashi]._state == EXIST)
		{
			hashi++;
			hashi %= _table.size();
		}

		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		++_size;
		return true;
	}
	HashDate<K, V>* Find(const K& key)
	{
		if (_table.size() == 0)
			return nullptr;
		Hash hash;
		size_t hashi = hash(key) % _table.size();
		
		while (_table[hashi]._state != EMPTY)
		{
			//如果找到key了，并且状态不是DELETE
			if (_table[hashi]._kv.first == key && _table[hashi]._state != DELETE)
			{
				return &_table[hashi];
			}
			hashi++;
			hashi %= _table.size();
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{
		HashDate<K, V>* ret = Find(key);
		if (ret)
		{
			ret->_state = DELETE;
			--_size;
			return true;
		}
		return false;
	}

	void Print()
	{
		for (int i = 0; i < _table.size(); i++)
		{
			if (_table[i]._state == EXIST)
			{
				cout << "i:" << i << " [" << _table[i]._kv.first << " " << _table[i]._kv.second << "]" << endl;

			}
		}
	}

private:
	//vector模拟哈希表
	vector<HashDate<K, V>> _table;
	size_t _size = 0;
};

void test_hash01()
{
	HashTable<int, int> Hash;
	int a[] = { 1,11,4,15,26,7 ,2};
	for (auto e : a)
	{
		Hash.Insert(make_pair(e, e));
	}
	Hash.Print();
	cout << endl;
}
void test_hash02()
{
	HashTable<int, int> Hash;
	int a[] = { 1,11,4,15,26,7,13,5,34,9 };
	for (auto e : a)
	{
		Hash.Insert(make_pair(e, e));
	}
	Hash.Print();
	cout << endl;
}


void test_hash03()
{
	HashTable<int, int> Hash;
	int a[] = { 1,11,4,15,26,7,13,5,34,9 };
	for (auto e : a)
	{
		Hash.Insert(make_pair(e, e));
	}
	Hash.Print();
	cout << endl << "find:" << endl;

	cout << (Hash.Find(11)->_kv).first << endl;
	cout << (Hash.Find(4)->_kv).first << endl;
	cout << (Hash.Find(5)->_kv).first << endl;
	cout << (Hash.Find(34)->_kv).first << endl;
	cout << "Erase:" << endl;
	Hash.Erase(11);
	cout << Hash.Find(11) << endl;
}

void test_hash04_string()
{
	string arr[] = { "苹果","西瓜","菠萝","草莓","菠萝","草莓" ,"菠萝","草莓"
		, "西瓜", "菠萝", "草莓", "西瓜", "菠萝", "草莓","苹果" };
	HashTable<string, int> countHT;
	for (auto& str : arr)
	{
		auto ptr = countHT.Find(str);
		if (ptr)
			ptr->_kv.second++;
		else
			countHT.Insert({ str,1 });
	}
	countHT.Print();
}

void test_hash05_string()
{
	HashFunc<string> hash;
	cout << hash({ "abc" }) << endl;
	cout << hash({ "bac" }) << endl;
	cout << hash({ "cba" }) << endl;
	cout << hash({ "bbb" }) << endl;
}

int main()
{
	test_hash05_string();
	return 0;
}