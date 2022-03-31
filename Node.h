#pragma once
template<class T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	char colour;//b or r
	int count;
};