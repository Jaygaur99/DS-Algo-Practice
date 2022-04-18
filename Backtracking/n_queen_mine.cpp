#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> ans;

bool isSafe(vector<string> &s, int row, int col) {
	for (int i = row; i >= 0; i--) {
		if (s[i][col] == 'Q')
			return false;
	}

	for (int i = row, j = col; i >= 0 and j >= 0; i--, j--) {
		if (s[i][j] == 'Q')
			return false;
	}

	for (int i = row, j = col; i >= 0 && j < s.size(); i--, j++) {
		if (s[i][j] == 'Q')
			return false;
	}
	return true;
}

void nQueenHelper(vector<string> &s, int row) {
	if (row == s.size()) {
		ans.push_back(s);
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		if (isSafe(s, row, i)) {
			s[row][i] = 'Q';
			nQueenHelper(s, row + 1);
			s[row][i] = '.';
		}
	}
}

void placeNQueens(int n) {
	vector<string> s(n, string(n, '.'));
	nQueenHelper(s, 0);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}
}

int main() {
	placeNQueens(5);
}