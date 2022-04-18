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

void addEdge(vi adj[], int u, int v){
    adj[u].push_back(v);
}

bool DFSRec(vi adj[], int s, bool visited[], bool recursionStack[]){
    visited[s] = true;
    recursionStack[s] = true;

    for(int u : adj[s]){
        if(visited[u] == false and DFSRec(adj, u, visited, recursionStack) == true)
            return true;
        else if(recursionStack[u] == true)
            return true;
    }
    recursionStack[s] = false;
    return false;
}

bool DFS(vi adj[], int v){
    bool visited[v];
    rep(i, 0, v)
        visited[i] = false;
    
    bool recursionStack[v]; // kindof
    rep(i, 0, v)
        recursionStack[i] = false;
    
    rep(i, 0, v){
        if(!visited[i]){
            if(DFSRec(adj, i, visited, recursionStack) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    /*
                            5
                         ↙️ ⬆️ 
        0 -> 1 <- 2 -> 3 -> 4
    */
    int v = 6;
    vi adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if(DFS(adj, v))
        cout<<"Cycle Found";
    else
        cout<<"No Cycle Found";
    return 0;
}