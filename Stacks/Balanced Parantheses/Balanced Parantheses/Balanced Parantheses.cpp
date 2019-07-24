/*
  C++ Program to check for balanced parentheses in an expression using stack.
  Given an expression as string comprising of opening and closing characters
  of parentheses - (), curly braces - {} and square brackets - [], we need to
  check whether symbols are balanced or not.
*/
#include<iostream>

#include "pch.h"

using namespace std;

#include<stack>
#include<string>

// Function to check whether two characters are opening 
// and closing of same type. 
bool ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	
	return false;
}

bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	char expression[51];
	printf("Enter an expression:  \n"); // input expression from STDIN/Console
	
	gets_s(expression);

	if (AreParanthesesBalanced(expression))
		printf("Balanced\n");
	else
		printf("Not Balanced\n");

}