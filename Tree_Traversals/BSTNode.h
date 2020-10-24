#pragma once
#include <iostream>
using namespace std;
class BSTNode
{
	int data;
private:
	BSTNode* left;
	BSTNode* right;
	friend class BST;
public:
	BSTNode(int d = 0);
	int getData();
};