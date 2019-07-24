// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int a = 5;
	
	int* p;

	p = &a;

	printf("%d\n", a);

	printf("%d\n", p);

	printf("%d\n", &a);

	*p = 1025;

	printf("%d\n", a);

	//Pointer Arithmetic

	printf("Address p is %d\n", p); // p = 11532920
	printf("Size of int is %d\n", sizeof(int));
	printf("%d\n", p + 1); // p = 11532924

	printf("%d\n", *(p + 1));

	char* p0;

	p0 = (char*)p;

	printf("size of char is %d bytes\n", sizeof(char));
	printf("Address: %d, value: %d\n", p0, *p0);
	printf("Address: %d, value: %d\n", p0 + 1, *(p0 + 1));

	// Void Pointer - Generic Pointer

	void* p1;

	p1 = p;

	printf("Address= %d\n", p1);

	// Pointer to Pointer
	printf("------------------------------\n");
	printf("Start of Pointer to Pointer\n");
	
	int x = 5;
	int *ptr;

	ptr = &x;

	int **q;

	q = &ptr;

	int ***r;

	r = &q;

	printf("%d\n", *ptr);
	printf("%d\n", *(*q));

	***r = 10;
	printf("%d\n", x);


	return 0;
}

