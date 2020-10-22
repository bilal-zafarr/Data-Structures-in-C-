#pragma once
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

