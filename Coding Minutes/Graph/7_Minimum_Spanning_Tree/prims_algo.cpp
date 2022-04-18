#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

class Graph{
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n){
        V = n;
        l = new vector<pair<int, int>> [n];
    }

    void addEdge(int x, int y, int w){
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst(){
        // Init min heap // weight, node
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> Q;

        // another array
        // visited array that denotes whether a node has been included in MST or Not
        vector<int> visited(V);
        int ans = 0;

        // begin
        Q.push({0, 0}); // weight, node
        while(!Q.empty()){
            // pick out edge with minimum weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if(visited[to]) // if visited then discard
                continue;
            
            ans += weight;
            visited[to] = 1;

            // Add new edges in the queue
            for(auto nbr : l[to]){
                if(visited[nbr.first] == 0){
                    Q.push({nbr.second, nbr.first});
                }
            } 
        }
        return ans;
    }
};

int main()
{
    Graph g(8);

    g.addEdge(0, 1, 25);
    g.addEdge(0, 5, 10);
    g.addEdge(1, 2, 14);
    g.addEdge(1, 6, 12);
    g.addEdge(2, 3, 11);
    g.addEdge(3, 6, 17);
    g.addEdge(3, 4, 20);
    g.addEdge(4, 6, 22);
    g.addEdge(4, 5, 23);

    cout<< g.prim_mst();
    return 0;
}