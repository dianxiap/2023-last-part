#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace dianxia
{
	enum state { EMPTY, EXIST, DELETE };

	template<class K,class V>
	struct HashNode
	{
		pair<K, V> _kv;
		state _state = EMPTY;
	};

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

	template<class K,class V,class Hash=HashFunc<K>>
	class HahsTab
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))return false;
			if (_table.size() == 0 || _size * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				HahsTab<K, V, Hash> newHash;
				newHash._table.resize(newSize);

				for (auto e : _table)
				{
					if (e._state == EXIST)
						newHash.Insert(e._kv);
				}
				//借助新表扩容完后再换回去
				_table.swap(newHash._table);
			}
			Hash hash;
			size_t hashi = hash(kv.first) % _table.size();

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

		HashNode<K, V>* Find(const K& key)
		{
			//表空找不到
			if (_table.size() == 0)return nullptr;

			Hash hash;
			size_t hashi = hash(key) % _table.size();
			//当前映射位置不空
			while (EMPTY != _table[hashi]._state)
			{
				//找到key并且不是已删除的
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
			HashNode<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_size;
				return true;
			}
			return false;
		}
	private:
		vector<HashNode<K, V>> _table;
		size_t _size = 0;
	};
}