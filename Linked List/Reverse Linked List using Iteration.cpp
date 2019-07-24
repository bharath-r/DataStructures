// Reverse Linked List using Iteration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Node {
	int data;
	Node* next;
};

Node* head;

void Reverse() {
	Node* current = new Node();
	Node* prev = new Node();
	Node* next = new Node();

	current = head;
	prev = NULL;

	while (current != NULL) {
		
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;

	}
	head = prev;
}

void Insert(int data, int n) {

	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;

	if (n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = new Node();
	temp2 = head;

	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}

	temp1->next = temp2->next;
	temp2->next = temp1;
}


void Print() {
	Node* temp = head;

	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL;
	Insert(2, 1);
	//Insert(3, 2);
	//Insert(4, 1);
	//Insert(5, 2);
	Print();

	printf("Reversing your LL\n");
	Reverse();

	Print();

	return 0;
}
