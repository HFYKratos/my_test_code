#include<iostream>
#include<list>
using namespace std;

template <class T>
struct ListNode
{
	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;

	ListNode(const T& value = T())
		:_data(value)
		, _prev(nullptr)
		, _next(nullptr)
	{}
};

template <class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, Ref, Ptr> Self;

	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &operator*();
	}


	ListIterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}
	ListIterator& operator--()
	{
		_node = _node->prev;
		return *this;
	}
	ListIterator& operator++(int)
	{
		ListIterator tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	ListIterator& operator--(int)
	{
		ListIterator tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	bool operator==(const ListIterator& it)
	{
		return _node == it._node;
	}
	bool operator!=(const ListIterator& it)
	{
		return _node != it._node;
	}
};

template <class T>
struct List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	void CreatHead()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	List()
	{
		CreatHead();
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin()const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end()const
	{
		return const_iterator(_head);
	}

	void push_back(const T& value = T())
	{
		/*pNode newNode = new Node(value);
		pNode tail = _head->_prev;
		tail->_next = newNode;
		newNode->_next = _head;
		newNode->_prev = tail;
		_head->_prev = newNode;*/
		insert(end(), value);
	}
	void push_front(const T& value = T())
	{
		insert(begin(), value);
	}
	void insert(iterator pos, const T& value)
	{
		pNode cur = pos._node;
		pNode newNode = new Node(value);
		pNode prev = cur->_prev;
		prev->_next = newNode;
		newNode->_next = cur;
		newNode->_prev = prev;
		cur->_prev = newNode;
	}

	void pop_back()
	{
		Erase(--end());
	}
	void pos_front()
	{
		Erase(begin());
	}
	iterator Erase(iterator pos)
	{
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			delete cur;
			cur = nullptr;
			prev->_next = next;
			next->_prev = prev;
			pos = iterator(next);
		}
		return pos;
	}
	void Clear()
	{
		if (!Empty())
		{
			iterator it = begin();
			while (it != end())
			{
				it = Erase(it);
			}
		}
	}

	template <class InputIterator>
	List(InputIterator first, InputIterator last)
	{
		CreatHead();
		while (first != last)
		{
			push_back(*first);
			++first;
		}
	}

	List(const List<T>& lst)
	{
		CreatHead();
		for (const auto& e : lst)
		{
			push_back(e);
		}
	}
	List<T>& operator=(List<T> lst)
	{
		swap(_head, lst._head);
		return *this;
	}

	bool Empty()
	{
		return _head == _head->_next;
	}

	size_t Size()
	{
		size_t sz = 0;
		for (const auto& e : *this)
			++sz;
		return sz;
	}

	~List()
	{
		Clear();
		if (_head)
		{
			delete _head;
			_head = nullptr;
		}
	}

private:
	pNode _head;
};

template<class T>
void PrintFor(const List<T>& l1)
{
	for (const auto& e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
}

template<class T>
void Print(const List<T>& l1)
{
	typename List<T>::const_iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << " ";
	}
	cout << endl;
}


void testlist()
{
	List<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	PrintFor(l1);
	l1.push_front(0);
	Print(l1);
}

int main()
{
	testlist();
	system("pause");
	return 0;
}