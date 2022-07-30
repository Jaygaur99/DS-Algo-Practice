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

class Solution {
public:
    vector<int> memo;
    int dp(int i, vector<int> &arr, int k){
        if(arr.size() == i) return 0;

        if(memo[i] != -1) return memo[i];

        int ans = 0, mx=0;
        for(int j=i; j<min((int)arr.size(), i+k); j++){
            mx = max(mx, arr[j]);
            ans = max(ans, mx * (j - i + 1) + dp(j+1, arr, k));
        }
        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memo.resize(arr.size(), -1);
        return dp(0, arr, k);
    }
};

void solve(){
    Solution s;
    vi arr={1,15,7,9,2,5,10}; 
    int k=3;
    cout<<s.maxSumAfterPartitioning(arr,k)<<endl;
    arr = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    k = 4;
    cout<<s.maxSumAfterPartitioning(arr,k)<<endl;
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