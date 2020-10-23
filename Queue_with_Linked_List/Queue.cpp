#include "Queue.h"

Queue::Queue(Node* f, Node* r)
{
	front = f;
	rear = r;
}

bool Queue::isEmpty()
{
	return front == nullptr || rear == nullptr;
}

bool Queue::enQueue(int d)
{
	Node* temp = new Node(d);
	if (isEmpty()) {
		rear = temp;
		front = temp;
		return true;
	}
	else {
		rear->next = temp;
		rear = rear->next;
		return true;
	}	
}

bool Queue::deQueue(int& d)
{
	if (isEmpty())
		return false;

	Node* temp = front;
	front = front->next;
	d = temp->d;
	delete temp;
	if (front == nullptr)
		rear = nullptr;
	return true;
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

void Queue::show()
{
	Node* temp = front;
	while (temp != nullptr)
	{
		cout << temp->d << " ";
		temp = temp->next;
	}
	cout << '\n'; 
}