#include <iostream>
#include <fstream>

using namespace std;

#include<iostream>
#include<assert.h>
using namespace std;

//����list�ڵ�
template<class T>
struct ListNode
{
	struct ListNode<T>* _next; // ָ����һ�����
	struct ListNode<T>* _prev; // ָ��ǰһ�����
	T _data; // ���洢������

	ListNode(const T& data = T()) // ���캯�� // ����һ���ڵ� 
		:_next(nullptr),
		_prev(nullptr),
		_data(data)
	{}
};
//�������Ķ���
// ���������ĺ���ֱ�Ϊ--��������T--T������--T��ָ��
template<class T, class Ref, class Ptr>
struct _list_iterator
{
	typedef ListNode<T> node;
	typedef _list_iterator<T, Ref, Ptr> self;
	node* _node;

	_list_iterator(node* node)
		:_node(node)
	{}

	self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	self operator--(int)
	{
		self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	Ref& operator*()
	{
		return _node->_data;
	}

	Ptr& operator->()
	{
		return &(_node->_data);
	}

	bool operator==(const self& s)
	{
		return _node == s._node;
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;
	}
};


// list��Ķ���
template<class T>
class list
{
	typedef ListNode<T> node;
public:
	typedef _list_iterator<T, T&, T*> iterator;
	typedef _list_iterator<T, const T&, const T*> const_iterator;

	list()
	{
		_head = new node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	// ���������乹��
	template<class Iterator>
	list(Iterator begin, Iterator end)
	{
		//��ʼ��
		_head = new node;
		_head->_next = _head;
		_head->_prev = _head;

		while (begin != end)
		{
			push_back(*begin);
			++begin;
		}
	}

	// �����ļ��е����ݳ�ʼ������
	void initFromFile(const string& filename)
	{
		ifstream file(filename);
		if (!file)
		{
			cerr << "Failed to open file." << endl;
			return;
		}

		T data;
		while (file >> data)
		{
			push_back(data);
		}

		file.close();
	}


	void swap(list<T>& tmp)
	{
		std::swap(_head, tmp._head);
	}
	//��������
	list(const list<T>& lt)
	{
		//��ʼ��
		_head = new node;
		_head->_next = _head;
		_head->_prev = _head;

		//�������乹��
		list<T> tmp(lt.begin(), lt.end());
		swap(tmp);
	}

	//��ֵ����
	list<T>& operator=(list<T> lt)
	{
		swap(lt);
		return *this;
	}

	~list()
	{
		clean();
		delete _head;
		_head = nullptr;
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}


	void push_back(const T& data)
	{
		insert(end(), data);
	}

	void pop_back()
	{
		erase(--end());
	}

	void push_front(const T& data)
	{
		insert(begin(), data);
	}

	void pop_front()
	{
		erase(begin());
	}

	void insert(iterator pos, const T& data)
	{
		node* newNode = new node(data);

		node* cur = pos._node;
		node* prev = cur->_prev;

		newNode->_prev = prev;
		prev->_next = newNode;
		newNode->_next = cur;
		cur->_prev = newNode;
	}

	iterator erase(iterator pos)
	{
		assert(pos != end());
		node* prev = pos._node->_prev;
		node* next = pos._node->_next;

		prev->_next = next;
		next->_prev = prev;
		delete pos._node;

		return iterator(next); // ����ɾ��λ�õ���һ��������λ��
	}
	
	// ���������������
	void reversePrint()
	{
		for (auto it = --end(); it != begin(); --it)
		{
			cout << *it << " ";
		}
		cout << *begin();
		cout << endl;
	}
	
	// ���������ݱ��浽�ļ�
	void saveToFile(const string& filename)
	{
		ofstream file(filename);
		if (!file)
		{
			cerr << "Failed to create file." << endl;
			return;
		}

		for (const auto& item : *this)
		{
			file << item << endl;
		}

		file.close();
	}
	void clean()
	{
		iterator it = begin();
		while (it != end())
		{
			//it = erase(it);
			erase(it++);
		}
	}
private:
	node* _head;
};

int main()
{
	list<int> myList;

	// ��ʼ������
	myList.initFromFile("data.txt");

	// ���������������
	myList.reversePrint();

	// ���������ݱ��浽�ļ�
	myList.saveToFile("output.txt");
}
