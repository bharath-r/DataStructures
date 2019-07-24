// Implementation using Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Node {

	int data;
	Node* next;

};

Node* head = NULL;
Node* tail = NULL;

void Enqueue(int data) {

	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;


	if (head == NULL && tail == NULL) {

		head = tail = temp;
		return;

	}
	
	tail->next = temp;
	tail = temp;

}

void Print() {

	Node* temp = new Node();
	temp = head;

	printf("Here's the queue for you:\n");

	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}

}

bool IsEmpty() {

	if (head == NULL) return true;
	else return false;

}

void Dequeue() {

	if (IsEmpty()) {
		printf("Error; Queue already empty\n");
		return;
	}
	
	Node* temp = new Node();
	temp = head;

	
	head = head->next;

	delete temp;


}



int main()
{
	Dequeue(); Enqueue(5); Print();

	Enqueue(15); Print();

	Enqueue(25); Dequeue();  Print();

	Enqueue(35); Print();

	Enqueue(45); Print();

}
