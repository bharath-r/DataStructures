// Call by Reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


void Increment(int *p)
{
	*p = (*p) + 1;
}
int main()
{
	int a = 10;
	Increment(&a);

	printf("%d\n", a);
	
	printf("------------------\n");
	printf("Pointers and Arrays\n");

	int A[5] = {2, 4, 5, 8, 1};
	int *p;
	p = A;
	
	for (int i = 0; i < 5; i++) {

		printf("Address= %d\n", A+i);
		printf("Address= %d\n", &(A[i]));

		printf("Value= %d\n", *(A+i));
		printf("Value= %d\n", A[i]);

	}

	return 0;


}

