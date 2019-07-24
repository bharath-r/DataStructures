// Delete Node at nth position.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Node {
	int data;
	Node* next;
};

Node* head;


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


void Delete(int data, int n) {

	Node* temp1 = new Node();
	temp1 = head;

	if (n == 1) {

		head = temp1->next;
		delete(temp1);
		return;
	}

	for (int i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
	}
	Node* temp2 = new Node();
	temp2 = temp1->next;
	temp1->next = temp2->next;
	delete(temp2);
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
	Insert(3, 2);
	Insert(4, 1);
	Insert(5, 2);
	printf("Before Deletion\n");
	Print();
	Delete(5, 2);
	printf("After Deletion\n");
	Print();

	return 0;
}
