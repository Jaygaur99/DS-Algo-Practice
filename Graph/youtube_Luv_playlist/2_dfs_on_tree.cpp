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
vi depth(N), height(N);

void dfs(int vertex, int par = 0){
    for(int child : g[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
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

    rep(i, 1, n+1){
        cout<<depth[i]<<" "<<height[i]<<endl;
    }

    return 0;
}

/* Input->
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
*/