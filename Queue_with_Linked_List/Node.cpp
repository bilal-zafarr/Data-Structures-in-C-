#include "Node.h"

Node::Node(int d, Node* n)
{
	this->d = d;
	next = n;
}
