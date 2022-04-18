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
#define rep(i, m, n) for(int i=m; i<n; i++)
const int N = 1e5 + 10;
vi g[N];
int par[N];

void dfs(int v, int p=0){
    par[v] = p;
    for(int child : g[v]){
        if(child == p)
            continue;
        dfs(child, v);
    }
}

vector<int> path(int v){
    vi ans;
    while(v != 0){
        ans.push_back(v);
        v = par[v];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n; 
    cin>>n;
    rep(i, 0, n-1){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);    
    int x, y;
    cin>>x>>y;
    vi path_x = path(x);
    vi path_y = path(y);
    int mn_ln = min(path_x.size(), path_y.size());
    int lca = -1;
    for(int i=0; i<mn_ln; i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        } else {
            break;
        }
    }
    cout<<lca<<endl;
    return 0;
}

/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
6 7
*/
