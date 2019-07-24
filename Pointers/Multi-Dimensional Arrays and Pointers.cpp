// Multi-Dimensional Arrays and Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
int Func(int (*C)[2][2])
{

}
int main()
{
	int C[3][2][2] = {{{2,5}, {7,9} },
						{{3,4}, {6,1}},
						{{0, 8}, {11, 13}}};

	printf("%d %d %d %d\n", C, *C, C[0], &C[0][0]);
	printf("%d\n", *(C[0][0] + 1));
}

