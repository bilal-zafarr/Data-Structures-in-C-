#include "BSTNode.h"

BSTNode::BSTNode(int d)
{
	data = d;
	left = nullptr;
	right = nullptr;
}

int BSTNode::getData()
{
	return data;
}