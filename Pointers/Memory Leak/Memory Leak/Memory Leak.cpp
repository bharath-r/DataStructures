// Memory Leak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

// "Simple Betting Game"
// Guess the position of the Queen in a stack of 3

int cash = 100;
void Play(int bet) {
	char C[3] = { 'J', 'Q', 'K' };
	printf("Shuffling....");

	srand(time(NULL)); //seeding random number generator
	int i;

	for (i = 0; i < 5; i++) {
		int x = rand() % 3;
		int y = rand() % 3;
		int temp = C[x];
		C[x] = C[y];
		C[y] = temp; //swap characters at position x and y
	}

	int PlayerGuess;
	printf("What's the postion of Queen\n");
	scanf("%d", &PlayerGuess);

	if (C[PlayerGuess - 1] = 'Q') {
		cash += 3 * bet;
		printf("You win! Result = %c%c%c Total Cash: ", C[0], C[1], C[2], cash);
	}
	else {
		cash -= bet;
		printf("You win! Result = %c%c%c Total Cash: ", C[0], C[1], C[2], cash);

	}
}
int main()
{
	int bet;
	while (cash > 0) {
		printf("What's your bet? in $");
		scanf("%d", &bet);
		if (bet == 0 || bet > cash) break;
		Play(bet);
	}

	return 0;
}

