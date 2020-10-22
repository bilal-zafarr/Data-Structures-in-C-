#include "BST.h"
#include <iostream>
using namespace std;

/*write a main testing all your functions after inserting following data in the order it is
given. You may add more data to it.
data: 55,24, 7, 1, 83, 56,12, 77, 79, 90, 5, 2, 99 */
int main() {

	BST t;

	t.insert(55);
	t.insert(24);
	t.insert(7);
	t.insert(1);
	t.insert(83);
	t.insert(56);
	t.insert(12);
	t.insert(77);
	t.insert(79);
	t.insert(90);
	t.insert(5);
	t.insert(2);
	t.insert(99);
	t.insert(55);

	BSTNode* temp;

	temp = t.search(24);

	if (temp != nullptr)
		cout << temp->getData() << '\n';
	else
		cout << "Not Found\n";

	temp = t.findSmallest();
	if (temp != nullptr)
		cout << temp->getData() << '\n';

	temp = t.findLargest();
	if (temp != nullptr)
		cout << temp->getData() << '\n';

	return 0;
}