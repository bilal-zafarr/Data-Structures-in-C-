#pragma once
class MinHeap
{
	int* arr;
	int capacity;
	int currSize;
public:
	MinHeap(int c);
	~MinHeap();
	bool isEmpty();
	bool isFull();
	bool insert(int d);
	int remove();
	void swap(int* x, int* y);
};