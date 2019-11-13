#define _CRT_SECURE_NO_WARNINGS 0
#include<iostream>
#include<stdio.h>
#include<assert.h>

using namespace std;

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;

	String(const char* str = "")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	String(const String& str)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}

	void Swap(String& str)
	{
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	const char* c_str()const
	{
		return _str;
	}

	void push_back(char c)
	{
		if (_size == _capacity)
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}

	void Append(const char* str)
	{
		int sz = strlen(str);
		if (_size + sz > _capacity)
		{
			reserve(_size + sz);
		}
		strcpy(_str + _size, str);
		_size = _size + sz;
	}

	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	String& operator+=(char c)
	{
		push_back(c);
		return *this;
	}
	String& operator+=(const String& str)
	{
		Append(str.c_str());
		return *this;
	}

	String& operator=(const String& str)
	{
		if (this != &str)
		{
			delete[] _str;
			_str = new char[strlen(str.c_str()) + 1];
			strcpy(_str, str.c_str());
		}
		return *this;
	}

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const_iterator cbegin()const
	{
		return _str;
	}

	const_iterator cend()const
	{
		return _str + _size;
	}

	size_t Size() const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	void resize(size_t sz, char c = '\0')
	{
		//sz > _capacity 
		if (sz > _capacity)
		{
			reserve(sz);
		}
		if (sz > _size)
		{
			memset(_str + _size, c, sz - _size);
		}
		_size = sz;
		_str[_size] = '\0';
	}

	char& operator[](size_t pos)
	{
		if (pos > _size)
		{
			cout << "failed" << endl;
		}
		return _str[pos];

	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void insert(size_t pos, const char c)
	{
		if (_size + 1 > _capacity)
		{
			reserve(_size + 1);
		}
		size_t end = _size + 1;
		while (end > pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = c;
		++_size;
	}

	void insert(size_t pos, const char* str)
	{
		int sz = strlen(str);
		if (_size + sz > _capacity)
		{
			reserve(_size + sz);
		}
		size_t end = _size + sz;
		while (end > pos + sz - 1)
		{
			_str[end] = _str[end - sz];
			end--;
		}
		int i = 0;
		while (*str)
		{
			_str[pos + i] = *str++;
			++i;
		}
		_size += sz;

	}

	void erase(size_t pos, int len)
	{
		if (pos + len)
		{

		}
		_size -= len;
	}

	size_t find(char ch, size_t pos = 0)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (ch == _str[i])
			{
				return i;
			}
		}
		return npos;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		char* start = strstr(_str + pos, str);
		if (start == nullptr)
		{
			return npos;
		}
		return 
	}


	void erase(iterator it)
	{
		if (it < end() && it >= begin())
		{
			return;
		}
		while (it != end())
		{
			*it = *(it + 1);
			++it;
		}
		--_size;
	}

	~String()
	{
		if(_str)
			delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

private:
	static const size_t npos;
	char* _str;
	size_t _size;
	size_t _capacity;
};

static const size_t npos = -1;

void teststring()
{
	String str("hello");
	String str2("world");
	String copy(str);
	str2 = str;
	return;
}

void teststring2()
{
	String str("hello");
	for (size_t i = 0; i < str.Size(); i++)
	{
		cout << str[i];
	}

	String::iterator sit = str.begin();
	while (sit != str.end())
	{
		*sit = 'c';
		cout << *sit;
		*sit++;
	}
}

void teststring3()
{
	String str = "hello";
	str.push_back(' ');
	cout << str.c_str() << endl;
	str.Append("world");
	cout << str.c_str() << endl;
	str += "Kratos";
	cout << str.c_str() << endl;
	str += ',';
	cout << str.c_str() << endl;
	String str2 = "The God of War.";
	str += str2;
	cout << str.c_str() << endl;
}

void teststring4()
{
	String str = "Kratos";
	//str.resize(10);
	cout << str.c_str() << endl;
	str.insert(0, 'H');
	str.insert(1, "FY");
	cout << str.c_str() << endl;
}


int main()
{
	teststring4();
	system("pause");
	return 0;
}