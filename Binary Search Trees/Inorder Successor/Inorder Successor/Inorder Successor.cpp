// Level Order Traversal (Breadth-First).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
using namespace std;
#include <iostream>
#include <queue>

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {

	BstNode* newNode = new BstNode();

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

BstNode* Search(BstNode* root, int data) {

	if (root == NULL) return NULL;

	if (root->data == data) return root;

	else if (root->data <= data) return	Search(root->right, data);

	else return Search(root->left, data);

}


BstNode* Insert(BstNode* root, int data) {

	if (root == NULL) {
		root = GetNewNode(data);
	}

	else {
		if (data <= root->data) {
			root->left = Insert(root->left, data);
		}

		else root->right = Insert(root->right, data);
	}

	return root;

}


void InOrderTraversal(BstNode* root) {

	BstNode* current = root;

	if (root == NULL) return;

	else {

		InOrderTraversal(current->left);
		printf("%d\n", current->data);
		InOrderTraversal(current->right);
	}

}


BstNode* GetSuccessor(BstNode* root, int data) {

	//Search the Node

	BstNode* current = Search(root, data);

	if (current == NULL) return NULL;

	//CASE 1: If the element has a right subtree
	if (current->right != NULL) {
		BstNode* temp = current->right;
		while (temp->left != NULL) temp = temp->left;
		return temp;
	}

	//CASE 2: If the element has no right subtree
	//Deepest Node for which there's the current node is in the left
	else {
		BstNode* successor = NULL;
		BstNode* ancestor = root;

		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor;
				successor = ancestor->left;
			}

			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}


int main()
{
	BstNode* root = new BstNode();

	root = Insert(root, 45);

	root = Insert(root, 55);

	root = Insert(root, 25);

	root = Insert(root, 75);

	root = Insert(root, 35);

	root = Insert(root, 15);

	printf("Level-Order before Deletion\n");
	InOrderTraversal(root);

	int i;
	/*printf("Enter the number to find the inorder successor for:\n");
	scanf_s("%d\n", &i);*/
	BstNode* successor = GetSuccessor(root, 35);
	printf("Level-Order Successor of 25 is %d", successor->data);

	
	

}
