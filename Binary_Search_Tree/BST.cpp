#include "BST.h"

BST::BST()
{
	root = nullptr;
}

void BST::insert(int d)
{
	if (root == nullptr) {
		root = new BSTNode(d);
		return;
	}
	BSTNode* curr = root;
	BSTNode* p = nullptr;
	while (curr!=nullptr)
	{
		p = curr;
		if (d < curr->data)
			curr = curr->left;
		else if (d > curr->data)
			curr = curr->right;
		else
			return;
	}
	if (d < p->data)
		p->left = new BSTNode(d);
	else if (d > p->data)
		p->right = new BSTNode(d);
}

BSTNode* BST::search(int d)
{
	BSTNode* curr = root;
	while (curr!=nullptr)
	{
		if (d < curr->data)
			curr = curr->left;
		else if (d > curr->data)
			curr = curr->right;
		else if (d == curr->data)
			return curr;
	}
	return nullptr;
}

BSTNode* BST::findSmallest()
{
	if (root == nullptr)
		return nullptr;

	BSTNode* curr = root;
	while (curr->left != nullptr)
		curr = curr->left;
	return curr;
}

BSTNode* BST::findLargest()
{
	if (root == nullptr)
		return nullptr;

	BSTNode* curr = root;
	while (curr->right != nullptr)
		curr = curr->right;
	return curr;
}
