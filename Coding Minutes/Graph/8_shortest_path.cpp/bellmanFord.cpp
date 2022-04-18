#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

vector<int> bellman_ford(int n,int src,vector<vector<int> > edges){ 
	// create a vector
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;

    // relax all edges V-1 times
    rep(i, 0, n-1){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // add int_max check to avoid overflow
            if(dist[u] != INT_MAX and dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    // negative wt cycle
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u] != INT_MAX and dist[u] + wt < dist[v]){
            cout<<"Negative wt cycle found";
            exit(0);
        }
    }

    return dist;
}


// 3 3
// 1 2 3
// 2 3 4
// 1 3 -10

int main(){
	int n,m;
	cin>>n>>m;

	//edge list 
	vector<vector<int>>  edges;       // (a,b,3) (c,d,5) ....

	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back({u,v,wt});
	}

	//bellman algorithm
	vector<int> distances = bellman_ford(n, 1, edges);

	for(int i=1;i<=n;i++){
		cout<<"Node "<<i<<" is at dist "<<distances[i]<<endl;
	}

	return 0;

}
