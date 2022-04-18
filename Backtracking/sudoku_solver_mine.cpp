#include<bits/stdc++.h>
using namespace std;
#define for_(x, n) for(int x=0; x<n; x++)
#define n 9

bool findEmptyLocation(int grid[n][n], int &row, int &col) {
	for_(i, n) {
		for_(j, n) {
			if (grid[i][j] == 0) {
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool isSafeInRowAndCol(int grid[n][n], int row, int col, int num) {
	for_(i, n)
	if (grid[row][i] == num)
		return false;
	for_(i, n)
	if (grid[i][col] == num)
		return false;
	return true;
}

bool isSafeInGrid(int grid[n][n], int row, int col, int num) {
	int rowFactor = row - (row % 3);
	int colFactor = col - (col % 3);

	for_(i, 3) {
		for_(j, 3) {
			if (grid[i + rowFactor][j + colFactor] == num) {
				return false;
			}
		}
	}
	return true;
}

bool isSafe(int grid[n][n], int row, int col, int num) {
	if (isSafeInRowAndCol(grid, row, col, num) and isSafeInGrid(grid, row, col, num))
		return true;
	return false;
}

bool solveSudoku(int grid[n][n]) {
	int row, col;
	if (!findEmptyLocation(grid, row, col)) {
		return true;
	}

	for (int i = 1; i <= n; i++) {
		if (isSafe(grid, row, col, i)) {
			grid[row][col] = i;
			if (solveSudoku(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}

int main() {
	int grid[n][n];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			grid[i][j] = s[j] - '0';
		}
	}
	cout << endl;
	solveSudoku(grid);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}