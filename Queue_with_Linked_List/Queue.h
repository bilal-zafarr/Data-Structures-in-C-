#pragma once
#include "Node.h"
class Queue
{
	Node* front;
	Node* rear;
public:
	Queue(Node* f = nullptr, Node* r = nullptr);
	bool isEmpty();
	bool enQueue(int d);
	bool deQueue(int& d);
	void show();
	~Queue();
};

