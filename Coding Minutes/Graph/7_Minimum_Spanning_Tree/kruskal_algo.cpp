#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

// DSU data structure
//Path Compression + Union By Rank
class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);

        rep(i, 0, n){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i){
        // base case
        if(parent[i] == -1){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph{
    vector<vector<int>> edgeList;
    int V;

public:
    Graph(int V){
        this->V = V;
    }

    // weight, from, to
    void addEdge(int x, int y, int w){
        edgeList.push_back({w, x, y});
    }

    int kruskal_mst(){
        // sort the list
        sort(edgeList.begin(), edgeList.end());

        // Init a DSU
        DSU s(V);

        int ans = 0;
        for(auto edge : edgeList){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(s.find(x) != s.find(y)){
                s.unite(x, y);
                ans += w;
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

    cout<<g.kruskal_mst();

    return 0;
}