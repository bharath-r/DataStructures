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

bool BSTUtil(BstNode* root, int min, int max) {

	if (root == NULL) return true;

	if (root->data > min &&
		root->data < max &&
		BSTUtil(root->left, min, root->data) &&
		BSTUtil(root->right, root->data, max))
		return true;

	else return false;

}


bool IsBST(BstNode* root) {

	return BSTUtil(root, INT_MIN, INT_MAX);

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

	if (IsBST(root)) printf("Oh yeah, it is a BST!\n");

	else printf("Oh no! It is not a BST!\n");


}
