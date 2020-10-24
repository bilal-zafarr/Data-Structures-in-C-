#include "Functions.h"

int main() {

	cout << "\n--------------Welcome To Expression Converter and Evaluator--------------\n\n";
	cout << "----MENU----\n";
	cout << " ->To Convert Infix Expression to Postfix  Enter 1\n";
	cout << " ->To Convert Postfix Expression to Infix  Enter 2\n";
	cout << " ->To Convert Infix Expression to Prefix   Enter 3\n";
	cout << " ->To Convert Prefix Expression to Infix   Ente  4\n";
	cout << " ->To Convert Prefix Expression to Postfix Enter 5\n";
	cout << " ->To Convert Postfix Expression to Prefix Enter 6\n";
	cout << " ->To Evaluate an Postfix Expression       Enter 7\n\n";
	cout << "         ENTER ANY OTHER KEY TO EXIT\n";

again:

	int choice; string s;
	cout << "\nEnter Choice From Menu: "; cin >> choice; cout << '\n';
	
	switch (choice)
	{
	case 1:
		goto infToPost;
		break;
	case 2:
		goto postToInf;
		break;
	case 3:
		goto infToPre;
		break;
	case 4:
		goto preToInf;
		break;
	case 5:
		goto preToPost;
		break;
	case 6:
		goto postToPre;
		break;
	case 7:
		goto eval;
		break;
	default:
		exit(0);
	}	

infToPost:
	cout << "Enter a Valid Expression in Infix Notation: ";
	cin >> s;
	cout << "Expression in Postfix Notation Is: " << InfixToPostfix(s) << '\n';
	goto cont;

postToInf:
	cout << "Enter a Valid Expression in Postfix Notation: ";
	cin >> s;
	cout << "Expression in Infix Notation Is: " << PostfixToInfix(s) << '\n';
	goto cont;

infToPre:
	cout << "Enter a Valid Expression in Infix Notation: ";
	cin >> s;
	cout << "Expression in Prefix Notation Is: " << InfixToPrefix(s) << '\n';
	goto cont;

preToInf:
	cout << "Enter a Valid Expression in Prefix Notation: ";
	cin >> s;
	cout << "Expression in Infix Notation Is: " << PrefixToInfix(s) << '\n';
	goto cont;

preToPost:
	cout << "Enter a Valid Expression in Prefix Notation: ";
	cin >> s;
	cout << "Expression in Postfix Notation Is: " << PrefixToPostfix(s) << '\n';
	goto cont;

postToPre:
	cout << "Enter a Valid Expression in Postfix Notation: ";
	cin >> s;
	cout << "Expression in Prefix Notation Is: " << PostfixToPrefix(s) << '\n';
	goto cont;
eval:
	int res;
	cout << "Enter a Valid Expression in Postfix Notation to Evaluate: ";
	cin >> s;
	res = evaluate(s);
	cout << "Answer Is: " << res << '\n';
	goto cont;

cont:
	cout << "\nDo You Wish To Continue? Y/N: ";
	char ch; cin >> ch;
	if (ch == 'Y' || ch == 'y')
		goto again;

	return 0;
}