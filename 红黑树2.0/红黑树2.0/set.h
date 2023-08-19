#pragma once
#include "БъЭЗ.h"
template<class K>
class set
{
	struct setKeyoft
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

public:
	typedef typename dianxia::RBTree<K, K, setKeyoft>::iterator iterator;
	typedef typename dianxia::RBTree<K, K, setKeyoft>::const_iterator const_iterator;

	iterator begin()
	{
		return _t.begin();
	}
	iterator end()
	{
		return _t.end();
	}
	pair<iterator, bool> insert(const K& key)
	{
		return _t.Insert(key);
	}

private:
	dianxia::RBTree<K, K, setKeyoft> _t;
};