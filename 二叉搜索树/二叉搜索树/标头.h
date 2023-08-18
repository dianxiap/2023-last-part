#pragma once
#include<iostream>
#include <algorithm>
using namespace std;

namespace dianxia
{
	template<class K>
	struct BSTreeNode
	{
		K _key;
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;

		BSTreeNode(const K& key=0)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}
		BSTree(const BSTree<K>& t)
		{
			_root=_copy(t._root);
		}
		BSTree<K>& operator(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}
		~BSTree()
		{
			_destroy(_root);
			_root = nullptr;
		}
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
			
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if(cur->_key>key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);
			if (cur->_key < key)
			{
				parent->_right = cur;
			}
			else parent->_left = cur;
			return true;
		}
		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//1.��Ϊ��
					if (cur->_left == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur = parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
						return true;
					}
					//2.��Ϊ��
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur = parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
						return true;
					}
					//3.���Ҷ���Ϊ��
					else
					{
						//������������С�ڵ�
						Node* minparent = cur;
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minparent = minRight;
							minRight = minRight->_left;
						}
						//�ҵ����滻��ǰcur��Ȼ��ɾ��minright
						cur->_key = minRight->_key;
						if (minRight = minparent->_left)
						{
							minparent->_left = minRight->_right;
						}
						else
						{
							minparent->_right = minRight->_right;
						}
						delete minRight;
						return true; 
					}

				}
			}
			return false;
		}
		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key < cur->_key)
					cur = cur->_left;
				else if (key > cur->_key)
					cur = cur->_right;
				else
					return cur;
			}
			return nullptr;
		}
		void Inorder()
		{
			_inorder(_root);
			cout << endl;
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
		Node* _copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			//�����¸��ڵ�
			Node* copynew = new Node(root->_key);
			//����������
			copynew->_left = _copy(root->_left);
			//����������
			copynew->_right = _copy(root->_right);
			return copynew;
		}
		void _inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_inorder(root->_left);
			cout << root->_key << " ";
			_inorder(root->_right);
		}
		Node* _root;
	};
}