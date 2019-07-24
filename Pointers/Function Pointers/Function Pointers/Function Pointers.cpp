// Function Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int Add(int a, int b)
{
	return a + b;
}

void A() {
	printf("Hello");
}

void B(void (*ptr) ()) {
	ptr();
}

void

int main()
{
	int c;
	int(*p) (int, int); //Parentheses is Important
	p = Add;  // p= &Add

	c = p(2, 3);  // c= (*p)(2, 3)
	printf("%d", c);

	printf("---------------------\n");

	printf("Callback Functions");

	B(A);

	return 0;
}
