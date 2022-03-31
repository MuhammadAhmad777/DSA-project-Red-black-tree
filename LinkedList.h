#pragma once
#include "Node1.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
protected:
	Node1<T>* head;
	Node1<T>* tail;
public:

	LinkedList();
	virtual void insertAtTail(T) = 0;
	virtual void insertAtHead(T) = 0;
	virtual T deleteFromHead() = 0;
	virtual T deleteFromTail() = 0;

	virtual T front() = 0;
	virtual T back() = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;

};

template<class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}
