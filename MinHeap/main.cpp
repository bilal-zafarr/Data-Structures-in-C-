#include "MinHeap.h"
#include <iostream>
using namespace std;

void swap(int* x, int* y);
void minHeapify(int* a, int size, int i);
void buildMinHeap(int* a, int size);
void heapSort(int* a, int size);


int main() {

	MinHeap h(11);

	h.insert(4);
	h.insert(7);
	h.insert(2);
	h.insert(8);
	h.insert(1);
	h.insert(14);
	h.insert(18);
	h.insert(20);
	h.insert(5);
	h.insert(19);
	h.insert(1);
	

	for (int i = 0; i < 11; i++)
		cout << h.remove() << " ";

	//---------heap sort----------

	int a[11];

	for (int i = 1; i < 11; i++)
		a[i] = rand() % 50 +10;

	cout << "\n\n--Unsorted--\n\n";

	for (int i = 1; i < 11; i++)
		cout << a[i] << ' ';

	cout << '\n';

	heapSort(a, 10);

	cout << "\n--Sorted with heap Sort--\n\n";

	for (int i = 1; i < 11; i++)
		cout << a[i] << ' ';
	cout << '\n';

	return 0;
}

//functions--------------
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void minHeapify(int* a, int size, int i)
{
	while (1)
	{
		int smallest = i;

		if (2 * i <= size && a[2 * i] < a[i])
			smallest = 2 * i;

		if (2 * i + 1 <= size && a[2 * i + 1] < a[smallest])
			smallest = 2 * i + 1;

		if (smallest == i)
			break;

		swap(&a[i], &a[smallest]);
		i = smallest;
	}
}

void buildMinHeap(int* a, int size)
{
	for (int i = size / 2; i > 0; i--)
		minHeapify(a, size, i);
}

void heapSort(int* a, int n)
{
	buildMinHeap(a, n);

	while (n > 0)
	{
		swap(&a[n], &a[1]);
		n--;
		minHeapify(a, n, 1);
	}
}
