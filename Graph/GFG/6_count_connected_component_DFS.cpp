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

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSRec(vector<int> adj[], int s, bool visited[]){
    visited[s] = true;
    // cout<<s<<" ";
    for(int u : adj[s]){
        if(!visited[u]){
            DFSRec(adj, u, visited);
        }
    }
}

int DFS(vector<int> adj[], int V){
    bool visited[V];
    int count = 0;
    for(int i=0; i<V; i++)
        visited[i] = false;
    rep(i, 0, V){
        if(!visited[i]){
            DFSRec(adj, i, visited);
            count += 1;
        }
    }
    return count;
}

int main()
{
    /*      0 ---- 1
            |      |  \     
            |      |    4
            |      |  /
            2 ---- 3
    */
    // int V=5;
	// vector<int> adj[V];
	// addEdge(adj,0,1); 
	// addEdge(adj,0,2); 
	// addEdge(adj,2,3); 
	// addEdge(adj,1,3); 
	// addEdge(adj,1,4);
	// addEdge(adj,3,4);

    int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);

    int count = DFS(adj, V);
    cout<< count <<endl;
    return 0;
}