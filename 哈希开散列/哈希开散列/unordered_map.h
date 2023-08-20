#pragma once
#include "БъЭЗ.h"

template<class K,class V,class Hash=HashFunc<K>>
class unordered_map
{
public:
	struct mapKeyoft;
	typedef typename HashTab<K, pair<K, V>, Hash, mapKeyoft>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	pair<iterator, bool> Inserat(const pair<K, V>& kv)
	{
		return _ht.Insert(kv);
	}
	bool erase(const K& k)
	{
		return _ht.Erase(k);
	}
	V& operatorp[](const K& key)
	{
		pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
		return ret.first->second;
	}
private:
	struct mapKeyoft
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};
	HashTab<K, pair<K, V>, Hash, mapKeyoft> _ht;
};