#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace dianxia
{
	template<class K,class V>
	struct AVLTreeNode
	{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;

		pair<K, V> _kv;
		int _bf;

		AVLTreeNode(const pair<K, V>& kv)
			:_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_kv(kv)
			,_bf(0)
		{}
	};

	template<class K,class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			//插入新节点
			cur = new Node(kv);
			if (parent->_kv.first > kv.first)
				parent->_left = cur;
			else parent->_right = cur;

			//更新平衡因子
			while (parent)
			{
				if (cur == parent->_right)
				{
					parent->_bf++;
				}
				else if (cur == parent->_left)
				{
					parent->_bf--;
				}

				if (parent->_bf == 1 || parent->_bf == -1)
				{
					parent = parent->_parent;
					cur = cur->_parent;
				}
				else if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					if (parent->_bf == 2)
					{
						//左单旋
						if (cur->_bf == 1)
						{
							RotateL(parent);
						}
						//右左双旋
						else
						{
							RotateRL(parent);
						}
					}
					else
					{
						//右单旋
						if (cur->_bf == -1)
						{
							RotateR(parent);
						}
						//左右双旋
						else
						{
							RotateLR(parent);
						}
					}
					break;
				}
				else
					assert(false);
			}
			return true;
		}
	private:
		void RotateL(Node* parent)
		{
			Node* subr = parent->_right;
			Node* subrl = subr->_left;
			Node* pparent = parent->_parent;

			parent->_right = subrl;
			if (subrl)
				subrl->_parent = parent;
			
			subr->_left = parent;
			parent->_parent = subr;
			
			if (parent == _root)
			{
				_root = subr;
				subr->_parent = nullptr;
			}
			else
			{
				if (pparent->_left = parent)
				{
					pparent->_left = subr;
				}
				else
				{
					pparent->_right = subr;
				}
				subr->_parent = pparent;
			}
			subr->_bf = parent->_bf = 0;
		}
		void RotateR(Node* parent)
		{
			Node* subl = parent->_left;
			Node* sublr = subl->_right;
			Node* pparent = parent->_parent;

			parent->_left = sublr;
			if (sublr)
				sublr->_parent = parent;
			
			subl->_right = parent;
			parent->_parent = subl;

			if (parent == _root)
			{
				_root = subl;
				subl->_parent = nullptr;
			}
			else
			{
				if (pparent->_left = parent)
				{
					pparent->_left = subl;
				}
				else
				{
					pparent->_right = subl;
				}
				subl->_parent = pparent;
			}
			parent->_bf = subl->_bf = 0;

		}
		void RotateLR(Node* parent)
		{
			Node* subl = parent->_left;
			Node* sublr = subl->_right;
			int bf = sublr->_bf;
			RotateL(parent->_left);
			RotateR(parent);

			sublr->_bf = 0;
			if (bf == 1)
			{
				parent->_bf = 0;
				subl->_bf = -1;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subl->_bf = 0;
			}
			else if (bf == 0)
			{
				parent->_bf = 0;
				subl->_bf = 0;
			}
			else assert(false);
		}
		void RotateRL(Node* parent)
		{
			Node* subr = parent->_right;
			Node* subrl = subr->_left;

			int bf = subrl->_bf;
			//p的右右旋
			RotateR(parent->_right);
			RotateL(parent);

			subrl->_bf = 0;
			if (bf == 1)
			{
				subr->_bf = 0;
				parent->_bf = -1;
			}
			else if (bf == -1)
			{
				subr->_bf = 1;
				parent->_bf = 0;
			}
			else if (bf == 0)
			{
				subr->_bf = 0;
				parent->_bf = 0;
			}
			else assert(false);
		}
		Node* _root;
	};
}