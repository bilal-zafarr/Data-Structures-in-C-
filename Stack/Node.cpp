#include "Node.h"

template<class T>
Node<T>::Node(T data, Node* n)
{
	d = data;
	next = n;
}
