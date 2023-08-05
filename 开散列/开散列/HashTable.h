#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace dianxia
{
	//仿函数，返回整型值
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
			{
				val = val * 131 + ch;
			}
			return val;
		}
	};

	//哈希表的节点
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	//对哈希表的前置声明
	template<class K, class T, class Hash, class keyoft>
	class HashTable;

	//哈希表的迭代器
	template<class K, class T, class Hash, class keyoft>
	class __Hash_Iterator
	{
	public:
		typedef HashNode<T> Node;
		typedef HashTable<K, T, Hash, keyoft> Ht;
		typedef __Hash_Iterator< K, T, Hash, keyoft> Self;
		__Hash_Iterator(Node* node, Ht* pht)
			:_node(node), _pht(pht)
		{}
		__Hash_Iterator()
			:_node(nullptr), _pht(nullptr)
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
			//在当前捅中++
			if (_node->_next)
			{
				_node = _node->_next;
			}
			//找下一个有效的捅
			else
			{
				Hash hash;
				keyoft kft;
				size_t i = hash(kft(_node->_data)) % _pht->_table.size();

				//从当前映射坐标的下一个位置开始找
				for (i += 1; i < _pht->_table.size(); i++)
				{
					//如果找到了
					if (_pht->_table[i])
					{
						_node = _pht->_table[i];
						break;
					}
				}
				//如果不存在有数据的桶
				if (i == _pht->_table.size())
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
		Node* _node;  //指向节点
		Ht* _pht;	  //指向当前表
	};

	template<class K, class T, class Hash, class keyoft>
	class HashTable
	{
	public:
		typedef HashNode<T> Node;
		template<class K, class T, class Hash, class keyoft>
		friend class __Hash_Iterator;

		typedef __Hash_Iterator<K, T, Hash, keyoft> iterator;

		//找到第一个有效的捅的节点
		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i])
					return iterator(_table[i], this);
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		//析构要进行特殊处理，遍历整个表，依次删除桶中节点的数据
		~HashTable()
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
			static const size_t __stl_prime_list[__stl_num_primes] =
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
				{
					return __stl_prime_list[i];
				}
			}
			return (size_t)-1;
		}

		pair<iterator, bool> Insert(const T& data)
		{
			Hash hash;
			keyoft koft;

			iterator ret = Find(koft(data));

			//去重
			if (ret != end())
			{
				return make_pair(ret, false);
			}

			//扩容  ---  如果插入的数据等于表的大小
			if (_size == _table.size())
			{
				vector<Node*> newTable;
				//扩容
				size_t newSize = __stl_next_prime(_table.size());
				newTable.resize(newSize, nullptr);

				//将旧表中的节点移动映射到新表
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						//将节点映射到新表中
						size_t hashi = hash(koft(cur->_data)) % newSize;
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}

			size_t hashi = hash(koft(data)) % _table.size();
			//头插新节点
			Node* newNode = new Node(data);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			++_size;

			return make_pair(iterator(newNode, this), true);
		}
		iterator Find(const K& key)
		{
			if (_table.size() == 0)return end();
			Hash hash;
			keyoft koft;
			size_t hashi = hash(key) % _table.size();

			//在当前捅里查找
			Node* cur = _table[hashi];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					return iterator(cur, this);
				}
			}
			return end();
		}

		bool Erase(const K& key)
		{
			if (_table.size() == 0)return false;
			Hash hash;
			keyoft koft;
			size_t hashi = hash(key) % _table.size();
			Node* pre = nullptr;
			Node* cur = _table[hashi];
			while (cur)
			{
				if (koft(cur->_data) == hash(key))
				{
					//1.删除的是链中第一个元素 --- 即头删
					if (pre == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					//2.捅的中间删除
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
		//表的长度
		size_t BuketSize()
		{
			return _table.size();
		}

		//数据个数
		size_t Size()
		{
			return _size;
		}
		//捅的个数
		size_t BucketNum()
		{
			size_t num = 0;
			for (size_t i = 0; i < BuketSize(); i++)
			{
				if (_table[i])num++;
			}
			return num;
		}
		//最长的桶
		size_t MaxBucketLenth()
		{
			size_t max_len = 0;
			size_t temp = 0;
			for (size_t i = 0; i < BuketSize(); i++)
			{
				if (_table[i])
				{
					size_t len = 1;
					Node* cur = _table[i]->_next;
					while (cur)
					{
						len++;
						cur = cur->_next;
					}
					if (len > max_len)
					{
						max_len = len;
						temp = i;
					}
				}
			}
			cout << "Max_len_i:" << temp << endl;
			return max_len;
		}

		void Print_map()
		{
			cout << "Print_map:" << endl;
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					cout << "i:" << i << " [" << cur->_data.first << " " << cur->_data.second << "] " << endl;
					cur = cur->_next;
				}
			}
		}

		void Print_set()
		{
			cout << "Print_set:" << endl;
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					cout << "i:" << i << " [" << cur->_data << "] " << endl;
					cur = cur->_next;
				}

			}
		}
	private:
		vector<Node*> _table;	//哈希表
		size_t _size = 0;		//放了多少个数据
	};
}
