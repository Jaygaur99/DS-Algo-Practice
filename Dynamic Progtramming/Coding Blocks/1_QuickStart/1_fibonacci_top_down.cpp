#include<bits/stdc++.h>
using namespace std;

int fib(int n, int dp[]) {
	// Base Case
	if (n == 1 or n == 0)
		return n;

	// Recursive Case
	// Lookup
	if (dp[n] != 0)
		return dp[n];

	int ans;
	ans = fib(n - 1, dp) + fib(n - 2, dp);
	return dp[ans] = ans;
}

int main() {
	int n;
	cin >> n;
	int dp[1000] = {0};

	cout << fib(n, dp);

	return 0;
}