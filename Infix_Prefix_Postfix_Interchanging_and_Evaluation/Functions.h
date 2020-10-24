#pragma once
#include "Stack.h"
#include "Stack.cpp"

int prec(char ch) {
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '/' || ch == '*' || ch == '%')
		return 2;
	else
		return -1;
}

int isOperator(char ch) //returns 1 for operator and 0 for operand
{
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '(' || ch == ')')
		return 1;
	else
		return 0;
}

string myReverse(string s) {
	string res = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == '(')
			res += ')';

		else if (s[i] == ')')
			res += '(';
		else
			res += s[i];
	}
	return res;
}

string InfixToPostfix(string infixExpr) {
	Stack<char> st;
	string out = "";
	
	for (unsigned int i = 0; i < infixExpr.size() ; i++)
	{
		if (!isOperator(infixExpr[i]))
			out += infixExpr[i];

		else if (infixExpr[i] == '(')
			st.push('(');

		else if (infixExpr[i] == ')') {
			while (st.toop()!= '(')
			{
				out += st.pop();
			}
			char c = st.pop();
		}

		else if (isOperator(infixExpr[i])) {

			while(prec(infixExpr[i]) <= prec(st.toop()))
			{
				out += st.pop();
			}
			st.push(infixExpr[i]);
		}		
	}
	while (!st.isEmpty())
		out += st.pop();
	return out;
}

string PostfixToInfix(string postfixExpr) {
	Stack<string> st;

	for (int i = 0; i < postfixExpr.size(); i++)
	{
		if (!isOperator(postfixExpr[i])) {
			string s = "";
			s += postfixExpr[i];
			st.push(s);
		}

		else if (isOperator(postfixExpr[i])) {
			string s1, s2;
			s2 = st.pop();
			s1 = st.pop();
			st.push("(" + s1 + postfixExpr[i] + s2 + ")");
		}
	}
	return st.pop();
}


string InfixToPrefix(string infixExpr) {

	string prefix;
	prefix = myReverse(infixExpr);
	prefix = InfixToPostfix(prefix);
	prefix = myReverse(prefix);
	return prefix;
}

string PrefixToInfix(string prefixExpr) {
	string infix;
	infix = myReverse(prefixExpr);
	infix = PostfixToInfix(infix);
	infix = myReverse(infix);
	return infix;
}

//Optional

string PrefixToPostfix(string prefixExpr) {
	string res;
	res = PrefixToInfix(prefixExpr);
	res = InfixToPostfix(res);
	return res;
}

string PostfixToPrefix(string postfixExpr) {
	string res;
	res = PostfixToInfix(postfixExpr);
	res = InfixToPrefix(res);
	return res;
}

bool isUnique(string arr,char element,int s) {
	for (int i = 0; i < s; i++)
		if (arr[i] == element)
			return false;
	return true;
}

int evaluatingTwoNum(int num1, int num2, char op) {
	switch (op)
	{
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '/':
		return num1 / num2;
		break;
	case '%':
		return num1 % num2;
		break;
	}
}

int evaluate(string postfixExpr) {
	string uniqueStr = "";

	for (int i = 0; i < postfixExpr.size(); i++)
		if (!isOperator(postfixExpr[i]))
			if (isUnique(postfixExpr, postfixExpr[i], i)) {
				uniqueStr += postfixExpr[i];
			}

	int* operandValues = new int[uniqueStr.size()];

	for (int i = 0; i < uniqueStr.size(); i++) {
		cout << "Enter the value of " << uniqueStr[i] << ": ";
		cin >> operandValues[i];
	}

	Stack<int> st;
	int num1, num2;
	for (int i = 0; i < postfixExpr.size(); i++)
	{
		if (!isOperator(postfixExpr[i])) {
			for (int j = 0; j < uniqueStr.size(); j++)
				if (postfixExpr[i] == uniqueStr[j])
					st.push(operandValues[j]);
		}
		else
		{
			num2 = st.pop();
			num1 = st.pop();
			st.push(evaluatingTwoNum(num1, num2, postfixExpr[i]));
		}
	}

	return st.pop();
}