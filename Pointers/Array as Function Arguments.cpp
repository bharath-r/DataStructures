// Array as Function Arguments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void Double(int* A, int size)
{
	
	int sum = 0;
	for (int i = 0; i < size; i++) {
		A[i] =  2*A[i]; // A[i] is *(A+i)
	}
}
int main()
{
	int A[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(A) / sizeof(A[0]);

	Double(A, size);

	for (int i = 0; i < size; i++) {
		printf("%d\n", A[i]); // A[i] is *(A+i)
	}
	return 0;
}

