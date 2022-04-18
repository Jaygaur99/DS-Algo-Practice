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

void topologicalSort(vi adj[], int v){
    vi in_degree(v, 0);
    // define the indegree of every node
    rep(u, 0, v)
        for(int x : adj[u])
            in_degree[x]++;
    
    // push the nodes in the queue with in_degree 0
    queue<int> q;
    rep(i, 0, v)
        if(in_degree[i] == 0)
            q.push(i);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v : adj[u]){
            // if(in_degree[v]-1 == 0){
            //     q.push(v);
            //     in_degree[v]--;
            // }
            if (--in_degree[v] == 0) 
                q.push(v); 
        }
    }
}

void addEdge(vi adj[], int u, int v){
    adj[u].push_back(v);
}

int main()
{
    /*
             0     1
            ↙️ ↘️  ↙️  ↘️
           2 -> 3    4
    */
    int v = 5;
    vi adj[v];
    addEdge(adj, 0, 2); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3);  
  
    cout << "Following is a Topological Sort of\n"; 
    topologicalSort(adj, v);
    return 0;
}