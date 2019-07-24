// Binary Search Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>   

struct BstNode{

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

BstNode* Insert(BstNode* root, int data) {

	if (root == NULL) {
		root = GetNewNode(data);
	}
	else {
		if (data <= root->data) {
			root->left = Insert(root->left, data);
		}
		else {
			root->right = Insert(root->right, data);
		}
	}
	return root;
}

bool Search(BstNode* root, int data) {

	if (root == NULL) return false;
	
	if (root->data == data) return true;

	else if (root->data <= data) return	Search(root->right, data);
	
	else return Search(root->left, data);

}

int MaxElement(BstNode* root) {

	BstNode* Max = new BstNode();

	Max = root;

	if (root->data == NULL) {
		printf("Tree is Empty!\n");
		return - 1;
	}

	else if (root->right == NULL) {
		return root->data;
	}
	 

	MaxElement(root->right);

}

int MinElement(BstNode* root) {

	BstNode* Min = new BstNode();

	Min = root;

	if (root->data == NULL) {
		printf("Tree is Empty!\n");
		return -1;
	}

	while (root->left != NULL) {
		root = root->left;
	}


	return root->data;

}


int Height(BstNode* root) {

	if (root == NULL) return -1;
	return (Height(root->left) < Height(root->right)) ? Height(root->right) + 1: Height(root->left) + 1;
}
int main()
{
	BstNode* root = NULL;

	root= Insert(root, 15);
	root= Insert(root, 10);
	root = Insert(root, 45);
	root = Insert(root, 25);
	root = Insert(root, 35);


	printf("The max element in this BST is: %d\n", MaxElement(root));	
	
	printf("The min element in this BST is: %d\n", MinElement(root));

	printf("The root element in this BST is: %d\n", root->data);

	printf("The left of root element in this BST is: %d\n", root->left->data);

	printf("The right of root element in this BST is: %d\n", root->right->data);

	printf("The right of %d element in this BST is: %d\n", root->right->left->data, root->right->left->right->data);

	printf("The left of %d element in this BST is: %d\n", root->right->data, root->right->left->data);


	/*printf("Enter the number to be searched: \n");
	int n;
	scanf_s("%d", &n);
	if (Search(root, n)) printf("Number Found!\n");
	else printf("No bueno, number not found\n");*/

	printf("The Height of the BST is %d\n", Height(root));

	return 0;
}