#pragma once
#include "БъЭЗ.h"

template<class K,class V,class Hash>
class unordered_set
{
public:
	struct Setkeyoft;
	typedef typename HashTab<K, K, Hash, Setkeyoft>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}
	pair<iterator, bool> insert(const K& key)
	{
		return _ht.Insert(key);
	}
	bool erase(const K& k)
	{
		return _ht.Erase(k);
	}


private:
	struct Setkeyoft
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	HashTab<K, K, Hash, Setkeyoft> _ht;
};