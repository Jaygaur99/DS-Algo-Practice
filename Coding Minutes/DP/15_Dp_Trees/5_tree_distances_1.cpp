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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define rep(x, start, end) for(int x=start; x<end; x++)
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
#define set_bits __builtin_popcountll
#define nd &&
#define oor || 
#define xoor ^ 
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
bool sameParity(int a, int b){ return (((a ^ b) & 1) == 0); }
bool sameParity(ll a, ll b){ return (((a ^ b) & 1) == 0); } 
/*------------------------------------------------------*/
// https://cses.fi/problemset/task/1132

const int N = 2e5 + 1;
vi gr[N];
int g[N], f[N];

void dfs_g(int cur, int par){
    for(auto x : gr[cur]){
        if(x != par){
            dfs_g(x, cur);

            g[cur] = max(g[cur], g[x] + 1);
        }
    }
}

void dfs_f(int cur, int par, int dis_par) {

	int max_1 = -1, max_2 = -1;

	for (auto x : gr[cur]) {
		if (x != par) {
			if (g[x] > max_1) max_2 = max_1, max_1 = g[x];
			else if (g[x] > max_2) max_2 = g[x];
		}
	}

	for (auto x : gr[cur]) {
		if (x != par) {

			int new_dis_par = dis_par;

			// for (auto y : gr[cur]) {
			// 	if (y != par && y != x) {
			// 		new_dis_par = max(g[y], new_dis_par);
			// 	}
			// }

			if (g[x] == max_1)
				new_dis_par = max(new_dis_par, max_2);
			else
				new_dis_par = max(new_dis_par, max_1);

			dfs_f(x, cur, new_dis_par + 1);

			// for any node in the subtree
			f[cur] = max(f[cur], g[x] + 1);
		}
	}

	// for any node in the supertree
	// supertree = compliment of subtree
	f[cur] = max(f[cur], dis_par + 1);

}

void solve(){   
    int n;
    cin>>n;

    rep(i, 0, n-1){
        int x, y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }

    // calculate the g values (max length child)
    dfs_g(1, -1);

    // calculate the f values by dis_par re-routing approach
    dfs_f(1, -1, -1);

    for(int i=1; i<=n; i++){
        printsp(f[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long t;
    t = 1;
    // cin>>t;
    while(t--)solve();
    return 0;
}