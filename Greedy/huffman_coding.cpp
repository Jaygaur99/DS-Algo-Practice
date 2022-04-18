#include<bits/stdc++.h>
using namespace std;

struct Node {
	int freq;
	char ch;
	Node *left, *right;
	Node(int f, char c, Node *l = NULL, Node *r = NULL) {
		freq = f;
		ch = c;
		left = l;
		right = r;
	}
};

struct compare {
	bool operator()(Node *l, Node *r) {
		return l->freq > r->freq;
	}
};

void printCodes(Node *root, string str) {
	// cout << root->ch << " " << root->freq << "\n";
	if (root->ch != '$') {
		cout << root->ch << " " << str << "\n";
		return;
	}
	printCodes(root->left, str + '0');
	printCodes(root->right, str + '1');
}

void printHuffmanCodes(vector<char> arr, vector<int> freq, int n) {
	priority_queue<Node*, vector<Node*>, compare> min_heap;
	for (int i = 0; i < n; i++) {
		min_heap.push(new Node(freq[i], arr[i]));
	}
	while (min_heap.size() != 1) {
		Node *left = min_heap.top();
		// cout << left << " ";
		min_heap.pop();
		Node *right = min_heap.top();
		min_heap.pop();

		Node *top = new Node(left->freq + right->freq, '$', left, right);
		min_heap.push(top);
	}
	printCodes(min_heap.top(), "");
}

int main() {
	vector<char> vec = {'a', 'd', 'e', 'f'};
	vector<int> freq = {30, 40, 80, 60};
	int size = vec.size();
	printHuffmanCodes(vec, freq, size);
}