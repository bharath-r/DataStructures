#include "pch.h"
#include <iostream>

struct Node {
	int data;
	Node* next;
};

Node* head = new Node();

void Print(Node* p) {

	if (p == NULL) return;


	printf("%d ", p->data);

	Print(p->next); // Recursive call

}

void Reverse(Node* p) {

	if (p->next == NULL) {

		head = p;
		return;

	}

	Reverse(p->next); // Recursive call
	
	Node* q = new Node();
	
	q = p->next;

	q->next = p;
	p->next = NULL;

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

	head = NULL;

	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 5);
	head = Insert(head, 6);

	Print(head);

	Reverse(head);

	Print(head);

	return 0;
}