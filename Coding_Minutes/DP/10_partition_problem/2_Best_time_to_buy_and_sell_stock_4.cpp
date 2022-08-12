#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long ll;
typedef long double lld;
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
void _print(lld t) {cerr << t;}
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
void printi(vpi p){ for(auto i : p){printsp("{"<<i.ff<<", "<<i.ss<<"}");}}
void printi(vi p){ for(auto i : p){printsp(i);}}
/*------------------------------------------------------*/

class Solution {
public:
    int memo[1001][2][101];
    int dp(int i, int buy, int k, vector<int>& prices)
    {
        if(i == prices.size()) return 0;
        if(memo[i][buy][k] != -1) return memo[i][buy][k];
        // dont buy / sell
        int ans = dp(i + 1, buy, k, prices);
        if(k == 0) return 0;
      
        if(buy){ // buy
            ans = max(ans, -prices[i] + dp(i+1, false, k, prices));
        } else { // sell
            ans = max(ans, prices[i] + dp(i+1, true, k-1, prices));
        }

        return memo[i][buy][k] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        // return dp(0, true, k, prices);
        int temp = dp(0, true, k, prices);
        // debug(memo);
        return temp;
    }
};

void solve(){
    Solution s;
    int k = 2;
    vi prices = {2,4,1};
    println(s.maxProfit(k, prices));
    k = 2; prices = {3,2,6,5,0,3};
    println(s.maxProfit(k, prices));
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