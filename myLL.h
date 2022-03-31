#pragma once
#include "LinkedList.h"

template <class T>
class myLL :public LinkedList<T>
{
public:
	T deleteFromTail();
	T deleteFromHead();
	void insertAtHead(T);
	void insertAtTail(T);
	void display();
	T front();
	T back();
	bool empty();
	int size();
};


template<class T>
T myLL<T>::deleteFromTail()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LinkedList is empty, returning JUNK" << endl;
		return 0;
	}

	else if (LinkedList<T>::head == LinkedList<T>::tail)
	{
		T retunringValue = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return retunringValue;
	}

	else
	{
		Node1<T>* helper = LinkedList<T>::head;

		while (1)
		{
			if (helper->next == LinkedList<T>::tail)
			{
				T retunringValue = LinkedList<T>::tail->data;
				delete LinkedList<T>::tail;
				LinkedList<T>::tail = helper;
				LinkedList<T>::tail->next = nullptr;
				return retunringValue;
			}

			else
			{
				helper = helper->next;
			}
		}

	}
}



template<class T>
T myLL<T>::deleteFromHead()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LinkedList is empty, returning JUNK" << endl;
		return 0;
	}

	else if (LinkedList<T>::head == LinkedList<T>::tail)
	{
		T retunringValue = LinkedList<T>::head->data;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
		return retunringValue;
	}
	else
	{
		Node1<T>* t = LinkedList<T>::head;
		T retr = t->data;
		t = t->next;
		delete LinkedList<T>::head;
		LinkedList<T>::head = nullptr;
		LinkedList<T>::head = t;
		return retr;
	}
}


template<class T>
void myLL<T>::insertAtHead(T value)
{
	Node1<T>* n = new Node1<T>;
	n->data = value;
	n->next = nullptr;

	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr) //this is the first Node1<T> to be inserted into LL
	{
		LinkedList<T>::head = n;
		LinkedList<T>::tail = n;
	}

	else
	{
		n->next = LinkedList<T>::head;
		LinkedList<T>::head = n;
	}
}


template<class T>

void myLL<T>::insertAtTail(T value)
{
	Node1<T>* n = new Node1<T>;
	n->data = value;
	n->next = nullptr;

	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		LinkedList<T>::head = n;
		LinkedList<T>::tail = n;
	}
	else
	{
		LinkedList<T>::tail->next = n;
		LinkedList<T>::tail = n;
	}
}

template<class T>

void myLL<T>::display()
{
	cout << "________________________________________________________________________________\n";
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LinkedList is empty\n";
	}
	else
	{
		Node1<T>* tem = LinkedList<T>::head;

		while (1)
		{
			cout << tem->data << " ";
			tem = tem->next;
			if (tem == nullptr)
			{
				break;
			}
		}
	}
	cout << "\n________________________________________________________________________________\n";
}

template<class T>

T myLL<T>::front()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LinkedList is empty, returning JUNK" << endl;
		return 0;
	}
	else
	{
		return LinkedList<T>::head->data;
	}
}
template<class T>
T myLL<T>::back()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		cout << "LinkedList is empty, returning JUNK" << endl;
		return 0;
	}
	else
	{
		return LinkedList<T>::tail->data;
	}
}


template<class T>
bool myLL<T>::empty()
{
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
int myLL<T>::size()
{
	int num = 0;
	if (LinkedList<T>::head == nullptr && LinkedList<T>::tail == nullptr)

	{
		cout << "Oops!LL is empty thus 0 is returning\n";
		return num;
	}
	else
	{
		Node1<T>* myTemp = LinkedList<T>::head;
		while (1)
		{
			num++;
			myTemp = myTemp->next;
			if (myTemp == nullptr)
			{
				break;
			}
		}
		return num;
	}
}
