#pragma once
#include "Node.h"
#include "Node.cpp"
template <class T>
class Queue
{
	Node<T>* front;
	Node<T>* rear;
public:
	Queue(Node<T>* f = nullptr, Node<T>* r = nullptr);
	bool isEmpty();
	bool enQueue(T d);
	bool deQueue(T& d);
	void show();
	~Queue();
};