#include "Queue.h"

template <class T>
Queue<T>::Queue(Node<T>* f, Node<T>* r)
{
	front = f;
	rear = r;
}

template <class T>
bool Queue<T>::isEmpty()
{
	return front == nullptr || rear == nullptr;
}

template <class T>
bool Queue<T>::enQueue(T d)
{
	Node<T>* temp = new Node<T>(d);
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

template <class T>
bool Queue<T>::deQueue(T& d)
{
	if (isEmpty())
		return false;

	Node<T>* temp = front;
	front = front->next;
	d = temp->d;
	delete temp;
	if (front == nullptr)
		rear = nullptr;
	return true;
}

template <class T>
Queue<T>::~Queue()
{
	Node<T>* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class T>
void Queue<T>::show()
{
	Node<T>* temp = front;
	while (temp != nullptr)
	{
		cout << temp->d << " ";
		temp = temp->next;
	}
	cout << '\n'; 
}