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

bool dfs_helper(vi graph[], int node, vi &visited, int parent, int color){
    visited[node] = color;
    for(auto nbr : graph[node]){
        if(visited[nbr] == 0){
            bool subprob = dfs_helper(graph, nbr, visited, node, 3-color); // 3 - color = new color => 3 - 1 = 2 => 3 - 2 = 1
            if(subprob == false){
                return false;
            }
        }
        else if (nbr != parent and color == visited[nbr]){
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int N){
    vi visited(N); // 0 - not visited, 1 - visited color is 1, 2 - visited color is 2
    bool ans = dfs_helper(graph, 0, visited, -1, 1); 

    // color
    rep(i, 0, N){
        cout<<i<<" - color "<<visited[i]<<endl;
    }

    return ans;
}

int main()
{
    int N, M;
    cin>>N >> M;

    vector<int> graph[N];
    // input
    while(M--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
 
    // BFS or DFS, by coloring the nodes at each steps (current node has color 1, nbr should have color 2)
    if(dfs(graph, N)){
        cout<<"Yes bipartite";
    } else {
        cout<<"No";
    }
    
    return 0;
}