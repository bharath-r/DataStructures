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

BstNode* FindMin(BstNode* root) {

	BstNode* Min = new BstNode();

	Min = root;

	if (root->data == NULL) {
		printf("Tree is Empty!\n");
		return NULL;
	}

	while (root->left != NULL) {
		root = root->left;
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


BstNode* Delete(BstNode* root, int data) {

	if (root == NULL) return root;

	else if (data < root->data) root->left= Delete(root->left, data);

	else if (data > root->data) root->right = Delete(root->right, data);

	else 
	{
		//Case 1: No Child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One Child
		else if (root->left == NULL) {
			BstNode* temp = root;

			root = root->right;

			delete temp;

		}

		else if (root->right == NULL) {
			BstNode* temp = root;

			root = root->left;

			delete temp;
		}

		else {
			BstNode* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}

	}

	return root;

}

void LevelOrderTraversal(BstNode* root) {

	if (root == NULL) return;

	queue<BstNode*> Q;

	Q.push(root);

	while (!Q.empty()) {

		BstNode* current = Q.front();

		printf("%d\n", current->data);

		if (current->left != NULL) Q.push(current->left);

		if (current->right != NULL) Q.push(current->right);

		Q.pop();

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
	LevelOrderTraversal(root);

	if (IsBST(root)) printf("Oh yeah, it is a BST!\n");

	else printf("Oh no! It is not a BST!\n");

	root = Delete(root, 25);

	printf("Level-Order after Deletion\n");
	LevelOrderTraversal(root);

	if (IsBST(root)) printf("Oh yeah, it is a BST!\n");

	else printf("Oh no! It is not a BST!\n");


}
