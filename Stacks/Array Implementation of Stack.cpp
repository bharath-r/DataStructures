// Array Implementation of Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x) {

	if (top == MAX_SIZE) {
		printf("Stack Overflow\n");
		return;
	}
	top++;
	A[top] = x;

}


void Pop() {

	if (top == -1) {
		printf("The array is empty!\n");
	}

	top--;
}

bool IsEmpty() {
	if (top == -1)
		return true;
}

int Top() {
	return A[top];
}

void Print() {


	printf("Stack: ");

	for (int i = 0; i <= top; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");


}

int main()
{
	Push(5); Print();

	Push(2); Print();

	Pop(); Print();

	Push(10); Print();

	Push(6); Print();

	Pop(); Print();

	if (IsEmpty())
		printf("Empty Vessel!\n");


}
