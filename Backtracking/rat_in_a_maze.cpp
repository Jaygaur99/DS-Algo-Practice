#include<bits/stdc++.h>
using namespace std;

void printPathsHelper(int **input, int n, int **solution, int x, int y) {
	if (x == n - 1 && y == n - 1) {
		solution[x][y] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}

	if (x < 0 || y < 0 || x >= n || y >= n ||
	        input[x][y] == 0 || solution[x][y] == 1) {
		return;
	}

	solution[x][y] = 1;
	printPathsHelper(input, n, solution, x - 1, y);
	printPathsHelper(input, n, solution, x + 1, y);
	printPathsHelper(input, n, solution, x, y - 1);
	printPathsHelper(input, n, solution, x, y + 1);

	solution[x][y] = 0;
}

bool hasPathHelper(int **input, int n, int **solution, int x, int y) {
	// Reached end
	if (x == n - 1 && y == n - 1)
		return true;

	// Check if we are at valid postition
	if (x < 0 || y < 0 || x >= n || y >= n ||
	        // check for input = 0 as there is a wall and
	        // solution = 1 for already visited
	        input[x][y] == 0 || solution[x][y] == 1) {
		return false;
	}

	solution[x][y] = 1;

	// go in all 4 directions
	if (hasPathHelper(input, n, solution, x - 1, y))
		return true;

	if (hasPathHelper(input, n, solution, x + 1, y))
		return true;

	if (hasPathHelper(input, n, solution, x, y - 1))
		return true;

	if (hasPathHelper(input, n, solution, x, y + 1))
		return true;

	// if nothing run means there is no path remove current
	// from visited and return false
	solution[x][y] = 0;
	return false;
}

bool hasPath(int **arr, int n) {
	// Just to keep track of visited
	int **solution = new int*[n];
	for (int i = 0; i < n; i++) {
		solution[i] = new int[n];
		for (int j = 0; j < n; j++) {
			solution[i][j] = 0;
		}
	}
	// Passing all to the function with initial position 0, 0
	// return hasPathHelper(arr, n, solution, 0, 0);
	printPathsHelper(arr, n, solution, 0, 0);
	return true;
}

int main() {
	int **arr;
	int n;
	cin >> n;
	arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cout << hasPath(arr, n) << endl;
}