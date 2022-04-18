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

void BFS(vector<int> adj[], int s, bool visited[]){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFSDir(vector<int> adj[], int v){
    bool visited[v+1];
    rep(i, 0, v)
        visited[i] = true;
    rep(i, 0, v){
        if(!visited[i])
            BFS(adj, i, visited);
    }   
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1); 
	addEdge(adj, 0, 2); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 4);
	addEdge(adj, 2, 4);

    BFSDir(adj, V); 
    return 0;
}