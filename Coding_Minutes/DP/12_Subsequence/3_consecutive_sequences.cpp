#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
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
#define all(x) (x).begin(), (x).end()
#define PI 3.141592653589793238462
#define INF 1e18
#define set_bits __builtin_popcountll
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define google(num_case) printsp("Case #"<<num_case<<":");
#ifdef JayKumarGaur99
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
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
bool sameParity(int a, int b) { return (((a ^ b) & 1) == 0); }
bool sameParity(ll a, ll b) { return (((a ^ b) & 1) == 0); }
/*------------------------------------------------------*/


// const int N = 1e5 + 1;
// vt<int> adj[N];

void solve(int case_num) {
	int n;
	cin >> n;
	vt<int> arr(n);
	rep(i, 0, n) {
		cin >> arr[i];
	}

	map<int, int> mp;
	rep(i, 0, n) {
		mp[arr[i]] = mp[arr[i] - 1] + 1;
	}
	int mx = INT_MIN;
	int num = -1;
	for (auto x : mp) {
		if (mx < x.ss) {
			mx = x.ss;
			num = x.ff;
		}
	}
	println(mx);
	vt<int> ans;
	for (int i = n - 1; i >= 0 && mx; i--) {
		if (num == arr[i]) {
			num--;
			ans.pb(i + 1);
			mx--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		printsp(ans[i]);
	}
	nextln;
}

int main()
{
#ifdef JayKumarGaur99
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();

	long t;
	t = 1;
	// cin>>t;
	rep(i, 1, t + 1) solve(i);

	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef JayKumarGaur99
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}
