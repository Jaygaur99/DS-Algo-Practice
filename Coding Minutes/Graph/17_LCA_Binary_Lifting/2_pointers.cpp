#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define pb push_back
#define rep(i, m, n) for(int i=m; i<n; i++)
const int N = 1e5+7;
vi gr[N];
int dep[N],Par[N]; // dep refers to depth

void dfs(int cur, int par){
    Par[cur] = par;
    dep[cur] = dep[par] + 1;
    for(auto x : gr[cur]){
        if(x != par){
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v){
    if(u == v)
        return v;
    // depth of u is more that depth of v
    if(dep[u] < dep[v]){ swap(u, v); }

    int diff = dep[u] - dep[v];
    // make both nodes depth same
    while(diff--){
        // move one above
        u = Par[u];
    }
    // until they are simple nodes keep climbing
    while(u != v){
        u = Par[u];
        v = Par[v];
    }
    return u;
}

int main()
{
    int n;
    cin>>n;
    rep(i, 1, n){
        int x, y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    // find depth
    dfs(1, 0);

    // rep(i, 1, n+1){
    //     cout<<i<<" "<<dep[i]<<"\n";
    // }

    cout<<LCA(9, 12)<<"\n";
    cout<<LCA(10, 12)<<"\n";
    cout<<LCA(7, 12)<<"\n";

    return 0;
}

/*
12
1 2
1 3
2 4
2 5
2 6
4 10
5 8
8 9
8 11
3 7
7 12
*/