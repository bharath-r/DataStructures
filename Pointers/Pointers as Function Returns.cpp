// Pointers as Function Returns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void PrintHola(){
	printf("Hola!\n");
}
int* Add(int* a, int* b)
{
	int* c = new int;
	*c = *a + *b;
	
	return c;
}
int main()
{
	int a = 8;
	int b = 10;

	int* c = Add(&a, &b);
	
	PrintHola();

	printf("%d\n", *c);


	return 0;
}
