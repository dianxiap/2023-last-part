#pragma once
#include "HashTable.h"
template<class K,class Hash=dianxia::HashFunc<K>>
class unordered_set
{
public:
	struct setkeyoft;
	typedef typename dianxia::HashTable<K, K, Hash, setkeyoft>::iterator iterator;
	iterator begin()
	{
		return  _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	pair<iterator, bool> insert(const K& kv)
	{
		return _ht.Insert(kv);
	}

	bool erase(const K& kv)
	{
		return _ht.Erase(kv);
	}

	void print()
	{
		_ht.Print_set();
	}
private:
	struct setkeyoft
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	dianxia::HashTable<K, K, Hash, setkeyoft> _ht;
};