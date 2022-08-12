#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
typedef double dbl;
typedef long double ldbl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sz(x) (int)(x).size()
#define vt vector
#define rep(x, start, end) for(ll x=start; x<end; ++x)
#define nextln cout<<"\n";
#define println(a) cout<<a<<"\n";
#define printsp(a) cout<<a<<" ";
#define print(a) cout<<a;
#define printvi(a) for(auto i : a)printsp(i);
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define INF 1e18
#define set_bits __builtin_popcountll
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
// reference from priyansh's template
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ldbl t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
bool sameParity(int a, int b) { return (((a ^ b) & 1) == 0); }
bool sameParity(ll a, ll b) { return (((a ^ b) & 1) == 0); }
/*------------------------------------------------------*/

class Solution {
public:
	int lengthOfLIS(vector<int>& a) {
		int n = a.size();
		vector<int> dp(n, 1);

		for (int i = 0; i < n; i++) {
			// dp[i] -> lis if it ends on its index
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i])
					dp[i] = max(dp[i], dp[j] + 1);
				debug(dp);
			}
			cerr << "\n" << i + 1 << ": ";
		}
		int ans = 1;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

void solve() {
	Solution s;
	vt<int> nums = {7, 49, 23, 8, 30, 22, 44, 28, 23, 9, 40, 15};
	println(s.lengthOfLIS(nums));
	// nums = {0, 1, 0, 3, 2, 3};
	// println(s.lengthOfLIS(nums));
	// nums = {7, 7, 7, 7, 7, 7, 7};
	// println(s.lengthOfLIS(nums));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t;
	t = 1;
	while (t--)solve();
	return 0;
}
