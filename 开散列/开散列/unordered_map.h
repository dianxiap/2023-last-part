#pragma once
#include "HashTable.h"

template<class K,class V,class Hash=dianxia::HashFunc<K>>
class unordered_map
{
public:
	struct mapkeyoft;
	typedef typename dianxia::HashTable<K, pair<K, V> ,Hash, mapkeyoft>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	pair<iterator, bool> insert(const pair<K, V>& kv)
	{
		return _ht.Insert(kv);
	}

	bool erase(const K& k)
	{
		return _ht.Erase(k);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
		return ret.first->second;
	}
	void print()
	{
		_ht.Print_map();
	}
private:
	struct mapkeyoft
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};
	dianxia::HashTable<K, pair<K, V>, Hash, mapkeyoft> _ht;
};