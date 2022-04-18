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

    bool dfs(int node, vector<bool> &visited, int parent){
        // mark node visited
        visited[node] = true;

        for(auto nbr : l[node]){
            if(!visited[nbr]){
                bool nbrFoundACycle = dfs(nbr, visited, node);
                if(nbrFoundACycle)
                    return true;
            } else if (nbr!=parent){
                return true;
            }
        }
        return false;
    }

    bool contains_cycle(){
        vector<bool> visited(V, false);
        return dfs(0, visited, -1);
    }
};

int main()
{
    Graph g(3);
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    

    cout<<(bool)g.contains_cycle();

    return 0;
}