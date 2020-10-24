#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
	top = nullptr;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return top == nullptr;
}

template<class T>
bool Stack<T>::push(T d)
{
	top = new Node<T>(d, top);
	return true;
}

template<class T>
T Stack<T>::pop()
{
	if (!isEmpty()) {
		Node<T>* t = top;
		T d = top->d;
		top = top->next;
		delete t;
		return d;
	}
	cout << "Stack is Empty\n";
	exit(1);
}

template<class T>
T Stack<T>::toop()
{
	if (!isEmpty()) {
		T d = top->d;
		return d;
	}
	else
		return NULL;
}

template<class T>
Stack<T>::~Stack()
{
	Node<T>* curr;
	while (!isEmpty()) {
		curr = top;
		top = top->next;
		delete curr;
	}
}