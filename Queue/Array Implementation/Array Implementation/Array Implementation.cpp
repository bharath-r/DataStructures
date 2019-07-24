// Array Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
	int A[MAX_SIZE];
	int front, rear;

public:

	//contructor set front and rear to 1

	Queue() {
		front = -1;
		rear = -1;
	}

	bool IsEmpty() {
		return (front == -1 && rear == -1);
	}

	bool IsFull() {
		return (rear + 1) % MAX_SIZE == front ? true : false;
	}

	//Inserts queue at the rear end
	void Enqueue(int x) {
		
		printf("Enqueuing\n");

		if (IsFull()) {
			printf("Error\n");
			return;
		}

		else rear = (rear + 1) % MAX_SIZE;

		A[rear] = x;
	}

	void Dequeue()
	{
		printf("Dequeuing \n");
		if (IsEmpty())
		{
			printf("Error\n");
			return;
		}
		else if (front == rear)
		{
			rear = front = -1;
		}
		else
		{
			front = (front + 1) % MAX_SIZE;
		}
	}

	int Front()
	{
		if (front == -1)
		{
			cout << "Error: cannot return front from empty queue\n";
			return -1;
		}
		return A[front];
	}

	/*This is not a standard function for Queue implementation.
		*/
	void Print()
	{
		if (IsEmpty())
		{
				return;
		}
		// Finding number of elements in queue  
		int count = ((rear + MAX_SIZE - front) % MAX_SIZE) + 1;
		cout << "Queue:  ";
		for (int i = 1; i < count; i++)
		{
			int index = (front + i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout << A[index] << " ";
		}
		cout << "\n\n";
	}


};

int main()
{
	Queue Q; // creating an instance of Queue. 
	Q.Enqueue(2);  Q.Print();
	Q.Enqueue(4);  Q.Print();
	Q.Enqueue(6);  Q.Print();
	Q.Dequeue();   Q.Print();
	Q.Enqueue(8);  Q.Print();
}
