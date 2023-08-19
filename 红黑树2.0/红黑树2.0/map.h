#pragma once
#include "��ͷ.h"

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
		//ret.firstָ����pair<iterator,bool> �е�iterator
		//ret.first->secondָ����iterator����->�����ָ��data��second��Ҳ����pair<K,V>�е�V
		return ret.first->second;
	}
	pair<iterator, bool> Insert(const pair<K, V>& kv)
	{
		return _t.Insert(kv);
	}
private:
	dianxia::RBTree<K, pair<K, V>, MapKeyoft> _t;
};