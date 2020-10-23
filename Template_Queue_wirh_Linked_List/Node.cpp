#include "Node.h"

template<class T>
Node<T>::Node(T d, Node* n)
{
	this->d = d;
	next = n;
}
