#include<iostream>
using namespace std;

//1
int TOH_Moves(int n,char s,char t,char g) {
	int count = 0;
	if (n > 0)
	{
		count = TOH_Moves(n - 1, s, g, t);
		//cout << "Move disk " << n << " from " << s << " to " << g << '\n';
		count++;
		count += TOH_Moves(n - 1, t, s, g);
	}
	return count;
}

//2
int count_character(char* str, char c) {
	int count = 0;
	if (str[0]) {
		if (str[0] == c)
			count++;
		count+=count_character(str+1, c);
	}	
	return count;
}

//3
void replace(char* s, char from, char to) {

	if (s[0]) {
		if (s[0] == from)
			s[0] = to;
		replace(s+1,from,to);
	}
}

//4
void printInAnyBase(int num, int base) {
	if (num == 0)
		return;
	printInAnyBase(num / base, base);
	cout << num % base;
}

//5
void letters(char c) {
	if (c == 'A') {
		cout << 'A';
		return;
	}
	else {
		letters(char(c - 1));
		cout << c;
		letters(char(c - 1));
	}
}

//6
int nthTerm(int n) {
	if (n == 1)
		return 0;

	return nthTerm(n - 1) + n - 1;
}

//7

void  printHourGlass(int  n, int b) {
	if (n < 1 )
		return;

	else {
		for (int i = 0; i < b; i++)
			cout << ' ';
		for (int i = 0; i < n; i++)
			cout << "* ";
		cout << '\n';

		printHourGlass(n - 2, b+2);

		for (int i = 0; i < b; i++)
			cout << ' ';
		for (int i = 0; i < n; i++)
			cout << "* ";
		cout << '\n';
	}
}


int main() {
		
	cout << TOH_Moves(3, 'S', 'T', 'G') << '\n';

	char s[] = "steve";

	cout << count_character(s, 'e');

	cout << '\n';

	char q[] = "steve";

	replace(q, 'e', 'a');

	cout << q << '\n';

	printInAnyBase(10, 2);

	cout << '\n';

	cout << nthTerm(10);

	cout << '\n';

	letters('D');

	cout << '\n';

	printHourGlass(5, 0);

	return 0;
}