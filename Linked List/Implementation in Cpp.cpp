// Implementation in Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Node{
	int data;
    Node* next;
};

Node* head;

// Insert Node at the Beginning
void Insert(int x) {
	
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	
	head = temp;
}

void Print() {
	
	Node* temp = head;
	printf("The list is\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	
	
	head = NULL;
	int n, x;
	printf("How many Numbers?\n");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		
		printf("Insert the Number at position %d\n", i+1);
		scanf_s("%d", &x);
		Insert(x);
		Print();
	}
	return 0;
}
