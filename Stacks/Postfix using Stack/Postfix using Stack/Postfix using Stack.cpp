// Postfix using Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool IsNumeric(char c) {

	if (c >= '0' && c <= '9') return true;
	return false;
}

int IsOperator(char c) {

	if (c == '+' || c == '-' || c == '*' || c == '/') return true;
	return false;

}

int PerformOperation(char operand, int operant1, int operant2) {

	if (operand == '+') return operant1 + operant2;
	else if (operand == '-') return operant1 - operant2;
	else if (operand == '*') return operant1 * operant2;
	else if (operand == '/') return operant1 / operant2;
}

int PostFixEval(string exp) {

	stack<int> S;

	for (int i = 0; i < exp.length(); i++) {

		if (IsNumeric(exp[i])) {
			S.push(exp[i]);
		}

		else if (IsOperator(exp[i])) {
			int operant2 = S.top();
			S.pop();
			int operant1 = S.top();
			S.pop();
			int result = PerformOperation(exp[i], operant1, operant2);
			S.push(result);
		}

		else printf("Error\n");

	}

	return S.top();

}

int main()
{
	string expression;
	cout << "Enter Postfix Expression \n";
	getline(cin, expression);
	int result = PostFixEval (expression);
	cout << "Output = " << result << "\n";


}


