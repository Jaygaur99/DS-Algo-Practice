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

class Graph{
    vi *l;
    int V;
public:
    Graph(int v){
        V = v;
        l = new vi[V];
    }

    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void bfs(int source){
        queue<int> q;
        vector<int> visited(V, 0);

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int f = q.front();
            cout<<f<<endl;
            q.pop();

            for(auto nbr : l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
    
};

int main()
{
    Graph g(7);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.bfs(1);

    return 0;
}