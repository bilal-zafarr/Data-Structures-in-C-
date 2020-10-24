#include "BST.h"

int main() {

	BST t;

	t.insert(3);
	t.insert(2);
	t.insert(6);
	t.insert(1);
	t.insert(4);
	t.insert(7);
	t.insert(5);

	t.preOrder();
	cout << '\n';

	t.inOrder();
	cout << '\n';

	t.postOrder();
	cout << '\n';

	t.levelOrder();
	cout << '\n';

	return 0;
}