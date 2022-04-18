#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
void printLevelOrder(TreeNode<int> * root);
TreeNode<int>* takeInputLevelWise();

TreeNode<int>* maxNode(TreeNode<int> *root) {
	TreeNode<int> *maxN = root;
	for (int i = 0; i < root->children.size(); i++) {
		TreeNode<int>* child = maxNode(root->children[i]);
		maxN->data = max(child->data, maxN->data);
	}
	return maxN;
}

int main() {
	TreeNode<int> *root = takeInputLevelWise();
	TreeNode<int> *maxN =  maxNode(root);
	cout << maxN->data;
}

















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