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
	while (curr != nullptr)
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
	while (curr != nullptr)
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

void BST::preOrder(BSTNode* n)
{
	if (n == nullptr)
		return;

	else
	{
		cout << n->data << " ";
		preOrder(n->left);
		preOrder(n->right);
	}
}

void BST::inOrder(BSTNode* n)
{
	if (n == nullptr)
		return;

	else
	{
		inOrder(n->left);
		cout << n->data << " ";
		inOrder(n->right);
	}
}

void BST::postOrder(BSTNode* n)
{
	if (n == nullptr)
		return;

	else
	{
		postOrder(n->left);
		postOrder(n->right);
		cout << n->data << " ";
	}
}

void BST::preOrder()
{
	preOrder(root);
}

void BST::inOrder()
{
	inOrder(root);
}

void BST::postOrder()
{
	postOrder(root);
}

void BST::levelOrder()
{
	Queue<BSTNode*> q;
	q.enQueue(root);

	while (!q.isEmpty())
	{
		BSTNode* temp = nullptr;
		q.deQueue(temp);
		cout << temp->data << " ";

		if (temp->left)
			q.enQueue(temp->left);
		if (temp->right)
			q.enQueue(temp->right);
	}
}