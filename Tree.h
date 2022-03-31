#pragma once
#include<iostream>
using namespace std;
#include"Node.h"
#include"myStack.h"
template<class T>
class Tree
{
protected:
	Node<T>* root;
public:
	Tree();

	
	virtual void insertValue(T)=0;
	virtual void inorder()=0;
	virtual void postorder()=0;
	virtual void preorder()=0;

	virtual bool search(T)=0;

	virtual void deleteDuplicates()=0;
	virtual void destroyCompleteTree()=0;
	virtual void  displayingParent(T)=0;
	~Tree();
};

template<class T>
Tree<T>::Tree()
{
	root = nullptr;
}
template<class T>
Tree<T>::~Tree()
{
	if (root != nullptr)
	{
		delete root;
		root = nullptr;
	}
}