#pragma once
#include "Node.h"
#include "Node.cpp"
template <class T>
class Stack
{
	Node<T>* top;
public:
	Stack();
	bool isEmpty();
	bool push(T d);
	T pop();
	T toop();
	~Stack();
};