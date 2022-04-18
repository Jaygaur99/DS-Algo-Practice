#include<bits/stdc++.h>
using namespace std;
#define for_(x, n) for(int x=0; x<n; x++)
#define nextln() cout<<"\n";
#define println(a) cout<<a<<"\n"
#define printsp(a) cout<<a<<" "
#define print(a) cout<<a;
#define printvi(a) for(auto i : a)printsp(i);
#define vi vector<int>
#define mp(a,b) make_pair(a, b)

bool myCmp(pair<int, int> a, pair<int, int> b) {
	return (a.second < b.second);
}

int maxActivities(pair<int, int> arr[], int n) {
	sort(arr, arr + n, myCmp);

	int prev = 0;
	int res = 1;

	for (int curr = 1; curr < n; curr++) {
		if (arr[curr].first >= arr[prev].second) {
			res++;
			prev = curr;
		}
	}
	return res;
}

int main() {
	pair<int, int> arr[] = {mp(12, 25), mp(10, 20), mp(20, 30)};

	int n = 3;

	cout << maxActivities(arr, n);
	return 0;
}