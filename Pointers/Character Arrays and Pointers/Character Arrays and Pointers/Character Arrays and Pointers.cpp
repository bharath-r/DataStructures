// Character Arrays and Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>


void print(const char* C) {
	int i = 0;
	while (C[i] != '\0')
	{
		printf("%c", C[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	char C[10]= "John";

	printf("Size in Bytes = %d\n", sizeof(C));

	int len = strlen(C);
	printf("%s\n", C);
	printf("Length= %d\n", len);


	//Print Functions
	char *C1 = "JOE";
	print(C1);

	return 0;
}
