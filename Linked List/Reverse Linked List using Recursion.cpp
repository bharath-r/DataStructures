// Reverse Linked List using Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Node {
	int data;
	Node* next;
};


void Print(Node* p) {

	if (p == NULL) return;
	

	printf("%d ", p->data);

	Print(p->next); // Recursive call
	
}

void ReversePrint(Node* p) {

	if (p == NULL) return;

	ReversePrint(p->next); // Recursive call
	
	printf("%d ", p->data);

}


Node* Insert(Node* head, int data) {

	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) head = temp;
	else {
		Node* temp1 = new Node();
		temp1 = head;

		while (temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

int main()
{
	Node* head = new Node();
	head = NULL;

	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 5);
	head = Insert(head, 6);

	Print(head);

	ReversePrint(head);

	return 0;
}
