#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack;

template <class T>
class Node
{
	T d;
	Node* next;
	friend Stack<T>;
public:
	Node(T data = 0, Node* n = nullptr);
};