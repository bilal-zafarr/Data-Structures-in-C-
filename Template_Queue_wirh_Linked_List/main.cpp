#include "Queue.h"
#include "Queue.cpp"

int main() {
	Queue<int> a;
	a.enQueue(1);
	a.show();

	a.enQueue(2);
	a.show();

	a.enQueue(3);
	a.show();

	cout << "=====\n";
	int d = 0;

	a.deQueue(d);
	cout << d << '\n';

	a.deQueue(d);
	cout << d << '\n';

	bool c = a.deQueue(d);
	cout << d << '\n';

	c = a.deQueue(d);
	cout << c << '\n';

	return 0;
}