// Reversing a String or Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring> 

using namespace std;
#include <stack> // from STL
#include <stdio.h>


void Reverse(char C[], int n) 
{
	stack<char> S;

	for (int i = 0; i < n; i++) {

		S.push(C[i]);
	
	}

	for (int i = 0; i < n; i++) {
		C[i] = S.top();
		S.pop();
	}

}
int main()
{
	char C[51];

	printf("Enter the string to be reversed:\n");

	gets_s(C);

	Reverse(C, strlen(C));

	printf("Reversed = %s ", C);
}
