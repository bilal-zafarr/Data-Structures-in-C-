#pragma once
#include <iostream>
using namespace std;

template <class T>
class  Queue;

template <class T>
class Node
{
	T d;
	Node* next;
	friend Queue<T>;
public:
	Node(T d = 0, Node* n = nullptr);
};