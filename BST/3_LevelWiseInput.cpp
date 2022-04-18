#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void printTree(BinaryTreeNode<int> *root);


BinaryTreeNode<int> * takeInputLevelWise() {
	int rootData;
	cout << "Enter root data " << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int> *> pendingNodes;

	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}

		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

int main() {
	BinaryTreeNode<int> *root = takeInputLevelWise();
	printTree(root);
	delete root;
}



void printTree(BinaryTreeNode<int> *root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ": ";

	if (root->left)
		cout << "L" << root->left->data;
	if (root->right)
		cout << "R" << root->right->data;
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}
