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

// Also called island problem
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

int BFSDir(vector<int> adj[], int v){
    bool visited[v+1];
    int count=0;
    rep(i, 0, v)
        visited[i] = false;
    rep(i, 0, v){
        if(!visited[i]){
            BFS(adj, i, visited);
            count++;
        }
    }   
    return count;
}

int main()
{
    /*
        0         3          5
      /   \       |        /   \
     1 --- 2      4       6     7
                                |
                                8 
    */

    int V=9;
	vector<int> adj[V];
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 2); 
	addEdge(adj, 1, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 7, 8);
    int count = BFSDir(adj, V); 
    cout<<"Count: "<<count<<endl;
    return 0;
}