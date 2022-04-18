#include<bits/stdc++.h>
using namespace std;

// Bottom up
int fib(int num) {
	vector<int> dp(10000, 0);
	dp[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[num];
}

int fib_space_opt(int n) {
	if (n == 0 or n == 1)
		return n;
	int a = 0;
	int b = 1;
	int c;
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main() {
	int num;
	cin >> num;

	cout << fib(num) << endl;
	cout << fib_space_opt(num) << endl;
	return 0;
}