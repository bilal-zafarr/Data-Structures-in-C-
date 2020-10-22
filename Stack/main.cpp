#include "Stack.h"
#include "Stack.cpp"

bool checkPalindrome(string str) {
	Stack<char> s;

	for (int i = 0; i < str.size() / 2; i++)
		s.push(str[i]);

	int checkFrom = str.size() / 2;

	if (str.size() % 2 != 0)
		checkFrom++;

	for (int i = checkFrom; i < str.size(); i++)
		if (str[i] != s.pop())
			return false;

	return true;
}

char correspondingBracket(char ch) {
	if (ch == ')')
		return '(';
	else if (ch == ']')
		return '[';
	else if (ch == '}')
		return '{';
}

bool balancedBrackets(string str) {
	Stack<char> s;

	for (int i = 0; i < str.size() ; i++)
	{
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (correspondingBracket(str[i]) != s.pop())
				return false;
		}
		else
			s.push(str[i]);
	}
	if (!s.isEmpty())
		return false;
	return true;
}

int main() {

	cout << balancedBrackets("{(})") << "\n";

	cout << checkPalindrome("bilal") << '\n';

	return 0;
}