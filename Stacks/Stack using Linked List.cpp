// Stack using Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct Node{

	int data;
	Node* next;

};

Node* top = NULL;

void Push(int x) {

	Node* temp = new Node();

	temp->data = x;
	temp->next = top;

	top = temp;

}

void Pop() {

	if (top == NULL) return;
	Node* temp = new Node();

	temp = top;
	top = top->next;

	delete(temp);

}

void Print() {

	Node* temp = new Node();
	temp = top;

	printf("Stack is: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	
	printf("\n");

}

int main()
{
	Push(5); Print();

	Push(10); Print();

	Pop(); Print();

	Push(120); Print();

	Pop(); Print();

	Pop(); Print();

	Push(210); Print();

}

