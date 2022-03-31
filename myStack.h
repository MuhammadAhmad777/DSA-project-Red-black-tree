#pragma once
#include"Stack.h"
template<class T>

class myStack:public Stack<T>
{
public:
	void push(T val);
	T pop();
	bool empty();
	int size();
	void display();
};


template<class T>
void myStack<T>::push(T val)
{
	Stack<T>::myObj.insertAtHead(val);
}
template<class T>
T myStack<T>::pop()
{
	if (Stack<T>::myObj.empty() == true)
	{
		cout << "Stack Already empty hence returning Garbage\n";
		return 0;
	}
	else
	{
		return Stack<T>::myObj.deleteFromHead();
	}
}

template<class T>
bool myStack<T>::empty()
{
	bool r = Stack<T>::myObj.empty();
	return r;
}
template<class T>
int myStack<T>::size()
{
	if (Stack<T>::myObj.empty() != true)
	{
		return Stack<T>::myObj.size();
	}
	else
	{

		int s = 0;
		return s;
	}
}
template<class T>
void myStack<T>::display()
{
	if (Stack<T>::myObj.empty() == true)
	{
		cout << "Stack is Empty\n";
	}
	else
	{
		int s = Stack<T>::myObj.size();
		myStack<T> temp;
		while (this->empty()!=true)
		{
			T d=this->pop();
			cout << d<<"\n";
			temp.push(d);
		}
		while (temp.empty()!=true)
		{
			this->push(temp.pop());
		}
	}
}