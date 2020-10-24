#pragma once
#include "BSTNode.h"
#include "Queue.h"
#include "Queue.cpp"
class BST
{
	BSTNode* root;
public:
	BST(); //constructor
	void insert(int d); //inserts data 'd' in BST
	BSTNode* search(int d); //returns pointer to node containing data 'd' and NULL if not

	//found in BST

	BSTNode* findSmallest(); //returns pointer to node holding the smallest value in BST
	BSTNode* findLargest(); //returns pointer to node holding the largest value in BST

	void preOrder(BSTNode* n);
	void inOrder(BSTNode* n);
	void postOrder(BSTNode* n);

	//driver functions
	void preOrder();
	void inOrder();
	void postOrder();

	void levelOrder();
};