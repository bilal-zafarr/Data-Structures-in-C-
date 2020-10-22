#include "MinHeap.h"

MinHeap::MinHeap(int c)
{
	currSize = 0;
	if (c > 0) {
		arr = new int[c + 1];
		capacity = c;
	}
	else {
		arr = nullptr;
		capacity = 0;
	}
}

MinHeap::~MinHeap()
{
	delete[]arr;
}

bool MinHeap::isEmpty()
{
	return currSize == 1;
}

bool MinHeap::isFull()
{
	return currSize == capacity;
}

bool MinHeap::insert(int d)
{
	if (currSize == capacity)
		return false;

	int i = ++currSize;

	while (i > 1 ) {
		if (d < arr[i / 2])
		{
			arr[i] = arr[i / 2];
			i = i / 2;

		}
		else
			break;
	}
	arr[i] = d;
	return true;
}

int MinHeap::remove()
{
	if(currSize == 0)
		return -1;

	int d = arr[1];
	arr[1] = arr[currSize--];

	int i = 1;

	while (i<=currSize)
	{
		int smallest = i;

		if (2 * i <= currSize && arr[2 * i] < arr[i])
			smallest = 2 * i;

		if (2 * i + 1 <= currSize && arr[2 * i + 1] < arr[smallest])
			smallest = 2 * i + 1;

		if (smallest == i)
			break;

		swap(&arr[i], &arr[smallest]);
		i = smallest;
	}
	return d;
}

void MinHeap::swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
