// Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Node {

	int data;
	Node* next;
	Node* prev;

};

Node* head = NULL;

void InsertAtHead(int data) {

	Node* temp = new Node();

	
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	if (head == NULL) {
		head = temp;
		return;
	}

	head->prev = temp;
	temp->next = head;
	head = temp;

}


void Print() {

	Node* temp = head;

	printf("The DLL is:\n");
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	printf("-----------\n");

}

int main()
{

	InsertAtHead(5); Print();

	InsertAtHead(7); Print();

	InsertAtHead(35); Print();

	InsertAtHead(10); Print();

}
