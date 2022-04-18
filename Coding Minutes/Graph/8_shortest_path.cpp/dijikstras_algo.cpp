#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

class Graph{
	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}

	void addEdge(int u,int v,int wt,bool undir = true){

		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}

	int dijkstra(int src,int dest){
        // data structure
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> s;

        // 1. init
        dist[src] = 0;
        s.insert({0, src});

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);

            // Iterate over the nbrs of node
            for(auto nbrPair : l[node]){

                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if(distTillNow + currentEdge < dist[nbr]){
                    // remove if such a nbrNode pair already exist
                    auto f = s.find({dist[nbr], nbr});
                    if(f != s.end()){
                        s.erase(f);
                    }
                    // insert the updated value pair 
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert(make_pair(dist[nbr], nbr));
                }
            }
        }
        // single source shortest dist to all other nodes
        rep(i, 0, V){
            cout<<"Node i "<<i<<" dist "<<dist[i]<<endl; 
        }

        return dist[dest];
    }
};

int main(){
    /*      1
        0 ----- 1
        |\      |  
      7 |  \ 4  | 1
        |    \  |
        3 ----- 2
        |     2
      3 |
        |
        4
    */
    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;
}