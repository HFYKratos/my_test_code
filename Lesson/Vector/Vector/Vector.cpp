#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
using namespace std;
template <class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		: _start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{}

	void PushBack(const T& val)
	{
		if (_finish == _eos)
		{
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		*_finish = val;
		++_finish;
	}

	size_t Capacity()
	{
		return _eos - _start;
	}

	size_t Size()const
	{
		return _finish - _start;
	}

	void Reserve(size_t n)
	{
		int sz = Size();
		if (n > Capacity())
		{
			T* tmp = new T[n];

			//memcpy(tmp, _start, sizeof(T)*sz);
			for (int i = 0; i < sz; i++)
			{
				tmp[i] = _start[i];
			}

			delete[] _start;
			_start = tmp;
			_finish = _start + sz;
			_eos = _start + n;
		}
	}

	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return _start[pos];
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator begin() const
	{
		return _start;
	}

	const_iterator end() const
	{
		return _finish;
	}

	void Insert(iterator pos, const T& val)
	{
		assert(pos >= begin() && pos <= end());
		int len = pos - _start;
		if (_finish == _eos)
		{
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		pos = _start + len;
		iterator end = _finish;
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
	}

	iterator Erase(iterator pos)
	{
		assert(pos >= begin() && pos <= end());
		iterator begin = pos + 1;
		while (begin < _finish)
		{

		}

	}

	void Resize(size_t n,const T& val = T())
	{
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				++finish++;
			}
		}
	}

	void PopBack();

	template<class InputItertor>
	Vector(InputItertor first, InputItertor last)
	{
		while (first != last)
		{
			PushBack(*first);
			++first;
		}

	}

	Vector(const Vector<T>& vec)
		:_start(new T[vec.Size()])
		, _finish(_start + vec.Size())
		, _eos(_start + vec.Capacity())
	{
		for (size_t i = 0; i < vec.Size(); i++)
		{
			_start[i] = vec[i];
		}
	}

	Vector<T>& operator=(const Vector<T>& vec)
	{
		Swap(vec);
		return *this;
	}

	void Swaq(Vector<T>& vec)
	{
		swaq(_start, vec._start);
		swaq(_finish, vec._finish);
		swaq(_eos, vec._eos);
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _eos = nullptr;
		}
	}

private:
	iterator _start;
	iterator _finish;
	iterator _eos;
};


template <class T>
void Print(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.Size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

template <class T>
void Print2(const Vector<T>& vec)
{
	Vector<T>::const_iterator it = vec.begin();
	for (it != vec.end)
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void testVec1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	Print(v);

}

void testVec2()
{
	Vector<string> s;
	s.PushBack("K");
	s.PushBack("r");
	s.PushBack("a");
	s.PushBack("t");
	s.Insert(s.end(), "o");
	s.Insert(s.end(), "s");
	
}


int main()
{
	testVec2();
	system("pause");
	return 0;
}