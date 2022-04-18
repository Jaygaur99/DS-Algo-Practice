// https://codeforces.com/problemset/problem/1037/C
#include<bits/stdc++.h>
using namespace std;
#define for_(x, n) for(int x=0; x<n; x++)

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int cost = 0;
	for (int i = 0; i < n;) {
		if (s[i] != t[i]) {
			// either swap or flip and increment the cost
			if (i + 1 < n && s[i] != s[i + 1] && s[i + 1] != t[i + 1]) {
				i += 2; // swapping
			} else {
				// flip
				i++;
			}
			cost++;
		} else {
			i++;
		}
	}

	cout << cost << endl;
	return 0;
}



