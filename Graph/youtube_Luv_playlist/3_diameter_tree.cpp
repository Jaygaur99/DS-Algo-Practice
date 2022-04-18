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
vi depth(N);

void dfs(int vertex, int par = 0){
    for(int child : g[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
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
    int max_depth = -1;
    int max_depth_node;
    rep(i, 1, n+1){
        if(max_depth < depth[i]){
            max_depth = depth[i];
            max_depth_node = i;
        }
        depth[i] = 0;
    }
    // cout<<"MAX DEPTH 1 "<<max_depth<<" "<<max_depth_node<<endl;
    dfs(max_depth_node);
    max_depth = -1;
    rep(i, 1, n+1){
        if(max_depth < depth[i]){
            max_depth = depth[i];
        }
    }
    cout<<max_depth<<endl;

    return 0;
}