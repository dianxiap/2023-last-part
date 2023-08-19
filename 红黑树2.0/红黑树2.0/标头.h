#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
namespace dianxia
{
	enum Colour
	{
		Black,
		Red
	};
	template<class T>
	struct RBTreeNode
	{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;
		Colour _col;

		RBTreeNode(const T& data)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(data)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct __RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef __RBTreeIterator<T, Ref, Ptr> Self;
		Node* _node;

		__RBTreeIterator(Node* node)
			:_node(node)
		{}

		__RBTreeIterator(const __RBTreeIterator<T, T&, T*>& it)
			:_node(it._node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		Self& operator++()
		{
			if (_node->_right)
			{
				Node* left = _node->_right;
				while (left->_left)
				{
					left = left->_left;
				}
				_node = left;
			}
			else
			{
				Node* cur = _node;
				Node* parent = _node->_parent;
				while (cur == parent->_right)
				{
					cur = cur->_parent;
					parent = parent->_parent;
					if (parent == nullptr)
						break;
				}
				_node = parent;
			}
			return *this;
		}
		Self& operator--()
		{
			if (_node->_left)
			{
				Node* right = _node->_left;
				while (right->_right)
				{
					right = right->_right;
				}
				_node = right;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && cur == parent->_left)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return *this;
		}
	};
	template<class K, class T, class Keyoft>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		typedef __RBTreeIterator<T, T&, T*> iterator;
		typedef __RBTreeIterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}
			return iterator(cur);
		}

		iterator end()
		{
			return iterator(nullptr);
		}
		const_iterator begin()
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}
			return const_iterator(cur);
		}

		const_iterator end()
		{
			return const_iterator(nullptr);
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			Keyoft kot;
			while (cur)
			{
				if (kot(cur->_data) < key)
					cur = cur->_right;
				else if (kot(cur->_data) > key)
					cur = cur->_left;
				else return cur;
			}
			return nullptr;
		}

		pair<iterator,bool> Insert(const T& data)
		{
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = Black;
				return make_pair(iterator(_root), true);
			}

			Keyoft kot;
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (kot(cur->_data) < kot(data))
				{
					parent = cur;
					cur = parent->_right
				}
				else if (kot(cur->_data) > kot(data))
				{
					parent = cur;
					cur = parent->_left;
				}
				else return make_pair(iterator(cur), false);
			}

			cur = new Node(data);
			Node* newnode = cur;

			if (kot(parent->_data) < kot(data))
			{
				parent->_right = cur;
			}
			else parent->_left = cur;

			cur->_parent = parent;

			while (parent && parent->_col == Red)
			{
				Node* graandparent = parent->_parent;
				assert(graandparent);
				assert(graandparent->_col == Black);

				if (parent == graandparent->_left)
				{
					Node* uncle = graandparent->_right;
					//1.u存在且为红
					if (uncle && uncle->_col == Red)
					{
						parent->_col = uncle->_col = Black;
						graandparent->_col = Red;
						//向上更新
						cur = graandparent;
						parent = cur->_parent;
					}
					//2.u不存在或u为黑
					else
					{
						if (cur == parent->_left)
						{
							RotateR(graandparent);
							parent->_col = Black;
							graandparent->_col = Red;
						}
						else
						{
							RotateL(parent);
							RotateR(graandparent);
							cur->_col = Black;
							graandparent->_col = Red;
						}
						break;
					}
				}
				else
				{
					Node* uncle = graandparent->_left;
					if (uncle && uncle->_col == Red)
					{
						parent->_col = uncle->_col = Black;
						graandparent->_col = Red;
						cur = graandparent;
						parent = cur->_parent;
					}
					else
					{
						if (cur == parent->_right)
						{
							RotateL(graandparent);
							parent->_col = Black;
							graandparent->_col = Red;
						}
						else
						{
							RotateR(parent);
							RotateL(graandparent);
							cur->_col = Black;
							graandparent->_col = Red;
						}
						break;
					}
				}

			}
			//返回之前的cur节点
			_root->_col = Black;
			return make_pair(iterator(newnode), true);
		}
		~RBTree()
		{
			_destroy(_root);
			_root = nullptr;
		}
	private:
		void _destroy(Node* root)
		{
			if (root == nullptr)
				return;
			_destroy(root->_left);
			_destroy(root->_right);
			delete root;
		}
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			Node* ppnode = parent->_parent;

			subR->_left = parent;
			parent->_parent = subR;

			if (ppnode == nullptr)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = subR;
				}
				else
				{
					ppnode->_right = subR;
				}

				subR->_parent = ppnode;
			}
		}

		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			Node* ppnode = parent->_parent;

			subL->_right = parent;
			parent->_parent = subL;

			if (parent == _root)
			{
				_root = subL;
				_root->_parent = nullptr;
			}
			else
			{
				if (ppnode->_left == parent)
				{
					ppnode->_left = subL;
				}
				else
				{
					ppnode->_right = subL;
				}
				subL->_parent = ppnode;
			}
		}
		
		Node* _root=nullptr;
	};
}