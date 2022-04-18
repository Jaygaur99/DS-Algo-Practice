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

    void addEdge(int i, int j){
        l[i].push_back(j);
        
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

    bool dfs(int node, vector<bool> &visited, vector<bool> &stack){
        // true if loop else false
        // arrive at a node
        visited[node] = true;
        stack[node] = true;

        // return true if loop found here itself
        for(int nbr : l[node]){
            if(stack[nbr] == true)
                return true;
            else if (visited[nbr] == false){
                bool nbrFoundCycle = dfs(nbr, visited, stack);
                if(nbrFoundCycle)
                    return true;
            }
        }

        // going back
        stack[node] = false;
        return false;
    }

    bool contains_cycle(){
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, visited, stack))
                    return true;
            }
        }
        return false;
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