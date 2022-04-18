#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
void printTree(TreeNode<int> *root);


TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter Root Data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();

		cout << "Enter number of children of " << front->data << endl;

		int numChild;
		cin >> numChild;

		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;

			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void printLevelOrder(TreeNode<int> * root) {
	if (root == NULL) {
		return;
	}

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();

		cout << front->data << ": ";
		for (int i = 0; i < front->children.size(); i++) {
			TreeNode<int> *child = front->children[i];
			cout << child->data << ", ";
			pendingNodes.push(child);
		}
		cout << endl;
	}
}

int main() {
	TreeNode<int>* root = takeInputLevelWise();
	printLevelOrder(root);
}









void printTree(TreeNode<int> *root) {
	// Edge case
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ", ";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++) {
		printTree(root->children[i]);
	}
}