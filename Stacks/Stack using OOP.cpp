// Stack using OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#define MAX_SIZE 101
using namespace std;


class Stack {

private:

	int A[MAX_SIZE];
	int top;

public:

	// Constructor
	Stack() {

		top = -1; //empty array, set top = -1
	
	}

	// Push Operation
	void Push(int x) {
		
		if (top == MAX_SIZE)
		{
			printf("Stack Overflow\n");
			return;
		}

		A[++top] = x;
	}

	// Pop Operation
	void Pop() {

		if (top == -1) {

			printf("Error: List already empty!\n");
			return;
		}

		top--;

	}

	// Check if Empty
	int IsEmpty() {

		if (top == -1) return 1;

		return 0;

	}

	// Printing Function
	void Print() {


		printf("Stack: ");
		
		for (int i = 0; i <= top; i++)
			printf("%d ", A[i]);

		printf("\n");

	}

	int Top() 
	{
		return A[top];
	}

};
int main()
{
	Stack S;

	S.Push(2); S.Print();
	
	S.Push(10); S.Print();

	S.Pop(); S.Print();

	S.Push(17); S.Print();

	printf("%d\n", S.Top());

	printf("%d\n", S.IsEmpty());

}
