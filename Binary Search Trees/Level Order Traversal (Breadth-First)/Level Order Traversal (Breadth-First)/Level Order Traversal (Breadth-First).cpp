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

	LevelOrderTraversal(root);


}
