#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t val = 0;
		for (auto ch : key)
			val = val * 131 + ch;
		return val;
	}
};

template<class T>
struct HashNode
{
	HashNode(const T& data)
		:_data(data)
		, _next(nullptr)
	{}
	T _data;
	HashNode<T>* _next;
};

// 对哈希表进行前置声明
template <class K, class T, class Hash, class keyOfT>
class HashTab;

template<class K, class T, class Hash, class Keyoft>
class __Hash_Iterator
{
public:
	typedef HashNode<T> Node;
	typedef HashTab<K, T, Hash, Keyoft> Ht;
	typedef __Hash_Iterator<K, T, Hash, Keyoft> Self;
	__Hash_Iterator(Node* node, Ht* pht)
		:_node(node)
		, _pht(pht)
	{}
	__Hash_Iterator()
		:_node(nullptr)
		, _pht(nullptr)
	{}

	T& operator*()
	{
		return _node->_data;
	}
	T* operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			Hash hash;
			Keyoft kft;
			size_t hashi = hash(kft(_node->_data)) % _pht->_table.size();
			for (hashi += 1; hashi <= _pht->_table.size(); hashi++)
			{
				if (_pht->_table[hashi])
				{
					_node = _pht->_table[hashi];
					break;
				}
			}
			if (hashi == _pht->_table.size())
				_node = nullptr;
		}
		return *this;
	}
	bool operator!=(const Self& self)
	{
		return _node != self._node;
	}
	bool operator==(const Self& self)
	{
		return _node == self._node;
	}
private:
	Node* _node;	//指向当前节点
	Ht* _pht;	//指向当前表
};
template<class K, class T, class Hash, class Keyoft>
class HashTab
{
public:
	typedef HashNode<T> Node;
	//迭代器设为友元，迭代器就可以使用HashTab中的成员了
	template<class K, class T, class Hash, class Keyoft>
	friend __Hash_Iterator;

	typedef __Hash_Iterator<K, T, Hash, Keyoft> iterator;

	iterator begin()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			if (_teble[i])
				return iterator(_table[i], this);
		}
		return end();
	}
	iterator end()
	{
		return iterator(nullptr, this);
	}
	~HashTab()
	{
		for (size_t i = 0; i < _table.size(); i++)
		{
			Node* cur = _table[i];
			while (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_table[i] = nullptr;
		}
	}
	inline size_t __stl_next_prime(size_t n)
	{
		static const size_t __stl_num_primes = 28;
		static const size_t  __stl_prime_list[__stl_num_primes] =
		{
		  53,         97,         193,       389,       769,
		  1543,       3079,       6151,      12289,     24593,
		  49157,      98317,      196613,    393241,    786433,
		  1572869,    3145739,    6291469,   12582917,  25165843,
		  50331653,   100663319,  201326611, 402653189, 805306457,
		  1610612741, 3221225473, 4294967291
		};
		//取下一次扩容的大小：
		for (size_t i = 0; i < __stl_num_primes; i++)
		{
			if (__stl_prime_list[i] > n)
				return __stl_prime_list[i];
		}
		return (size_t)-1;
	}
	pair<iterator, bool> Insert(const T& data)
	{
		Hash hash;
		Keyoft kot;

		iterator ret = Find(kot(data));
		if (ret != end())
		{
			return make_pair(ret, false);
		}

		if (_size == _table.size())
		{
			vector<Node*> newtable;
			size_t newsize = __stl_next_prime(_table.size());
			newtable.resize(newsize, nullptr);

			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					size_t hashi = hash(kot(cur->_data)) % newtable.size();
					cur->_next = newtable[hashi];
					newtable[hashi] = cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newtable);
		}
		size_t hashi = hash(kot(data)) % _table.size();
		Node* newnode = new Node(data);
		newnode->_next = _table[hashi];
		_table[hashi] = newnode;
		++_size;

		return make_pair(iterator(newnode, this), true);
	}
	iterator Find(const K& key)
	{
		if (_table.size() == 0)return end();
		Hash hash;
		Keyoft kot;
		size_t hashi = hash(key) % _table.size();
		Node* cur = _table[hashi];

		while (cur)
		{
			if (kot(cur->_data) == key)
			{
				return iterator(cur, this);
			}
			cur = cur->_next;
		}
		return end();
	}
	bool Erase(const K& key)
	{
		if (_table.size() == 0)return false;
		Hash hash;
		Keyoft kot;
		size_t hashi = hash(key) % _table.size();
		Node* pre = nullptr;
		Node* cur = _table[hashi];
		while (cur)
		{
			if (kot(cur->_data) == hash(key))
			{
				if (pre == nullptr)
				{
					_table[hashi] = cur->_next;
				}
				else
				{
					pre->_next = cur->_next;
				}
				delete cur;
				--_size;
				return true;
			}
			pre = cur;
			cur = cur->_next;
		}
		return false;
	}
private:

	vector<Node*> _table;
	size_t _size = 0;
};
