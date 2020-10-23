#pragma once
#include <iostream>
using namespace std;
class  Queue;
class Node
{
	int d;
	Node* next;
	friend Queue;
public:
	Node(int d = 0, Node* n = nullptr);
};

