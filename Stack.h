#pragma once
#include"myLL.h"
template <class T>
class Stack
{
protected:
	myLL<T> myObj;
public:
	virtual void push(T) = 0;
	virtual T pop() = 0;
	virtual bool empty() = 0;
	virtual int size()=0;
};

