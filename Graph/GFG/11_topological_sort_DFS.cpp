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

void DFS(vi adj[], int u, stack<int> &st, bool visited[]){
    visited[u] = true;

    for(int v : adj[u])
        if(!visited[v])
            DFS(adj, v, st, visited);
    
    st.push(u);
}

void topologicalSort(vi adj[], int v){
    bool visited[v];
    rep(i, 0, v)
        visited[i] = false;
    stack<int> st;

    rep(i, 0, v)
        if(!visited[i])
            DFS(adj, i, st, visited);
    
    while(!st.empty()){
        int u = st.top();
        st.pop();
        cout<<u<<" ";
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main()
{
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);  
  
    cout << "Following is a Topological Sort of\n"; 
    topologicalSort(adj,V);
    return 0;
}