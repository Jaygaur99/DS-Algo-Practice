#include<bits/stdc++.h>
using namespace std;
#define for_(x, n) for(int x=0; x<n; x++)
#define nextln() cout<<"\n";
#define println(a) cout<<a<<"\n"
#define printsp(a) cout<<a<<" "
#define print(a) cout<<a;
#define printvi(a) for(auto i : a)printsp(i);
#define vi vector<int>

bool myCmp(pair<int, int> a, pair<int, int> b) {
	double r1 = (double) a.first / a.second;
	double r2 = (double) b.first / b.second;

	return r1 > r2;
}

double fKnapSack(int W, pair<int, int> arr[], int n) {
	sort(arr, arr + n, myCmp);
	double res = 0.0;

	for (int i = 0; i < n; i++) {
		if (arr[i].second <= W) {
			res += arr[i].first;
			W -= arr[i].second;
		} else {
			res += arr[i].first * ((double) W / arr[i].second);
			break;
		}
	}
	return res;
}

int main() {
	pair <int, int> arr[] = {make_pair(30, 18), make_pair(21, 15), make_pair(18, 10)};
	int n = 3, W = 20;
	cout << fKnapSack(W, arr, n);
	return 0;
}