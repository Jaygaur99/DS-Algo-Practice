#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
void printLevelOrder(TreeNode<int> * root);
TreeNode<int>* takeInputLevelWise();

int numNodes(TreeNode<int> *root) {
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += numNodes(root->children[i]);
	}
	return ans;
}

int main() {
	TreeNode<int> *root = takeInputLevelWise();
	cout << numNodes(root);
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