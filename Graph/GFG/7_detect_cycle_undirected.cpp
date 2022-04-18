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

void addEdge(vi adj[], int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool DFSRec(vi adj[], int s, bool visited[], int parent){
    visited[s] = true;
    for(int i : adj[s]){
        if(!visited[i]){
            if(DFSRec(adj, i, visited, s) == true)
                return true;
        }
        else if(i != parent)
            return true;
    }
    return false;
}

bool DFS(vi adj[], int v){
    bool visited[v];
    rep(i, 0, v){
        visited[i] = false;
    }
    rep(i, 0, v){
        if(!visited[i]){
            if(DFSRec(adj, i, visited, -1) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";
    return 0;
}