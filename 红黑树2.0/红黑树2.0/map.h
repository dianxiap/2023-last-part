#pragma once
#include "标头.h"

template<class K,class V>
class Map
{
	struct MapKeyoft
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};
public:
	typedef typename dianxia::RBTree<K, pair<K, V>, MapKeyoft>::iterator iterator;

	iterator begin()
	{
		return _t.begin();
	}
	iterator end()
	{
		return _t.end();
	}
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
		//ret.first指的是pair<iterator,bool> 中的iterator
		//ret.first->second指的是iterator调用->运算符指向data的second，也就是pair<K,V>中的V
		return ret.first->second;
	}
	pair<iterator, bool> Insert(const pair<K, V>& kv)
	{
		return _t.Insert(kv);
	}
private:
	dianxia::RBTree<K, pair<K, V>, MapKeyoft> _t;
};