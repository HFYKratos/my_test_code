#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() 
	{
		stack<int> s1;
		stack<int> s2;
	}

	void push(int x) 
	{
		s1.push(x);
		if (s2.empty() != true)
		{
			if (s2.top() >= x)
			{
				s2.push(x);
			}
		}
		else
		{
			s2.push(x);
		}
	}

	void pop() 
	{
		if (s1.empty() == false)
		{
			s1.pop();
		}
	}

	int top()
	{
		return s1.top();
	}

	int getMin() 
	{
		int num = s2.top;
		if(s1.top() == s2.top())
		{
			s1.pop();
			s2.pop();
		}
		return num;
	}
private:
	stack<int> s1;
	stack<int> s2;
};