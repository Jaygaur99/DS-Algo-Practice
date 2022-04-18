#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
#define INF 10000

vector<vector<int>>  floyd_warshall(vector<vector<int>> graph){
    vector<vector<int>> dist(graph);
    int V = graph.size();
    // phases, in kth phase we included vertices(1, 2, ... k) as intermediate vertices
    rep(k, 0, V){
        rep(i, 0, V){
            rep(j, 0, V){
                // if vertex k is included, and can we minimize the dist?
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> graph = {
                                    {0,INF,-2,INF},
                                    {4,0,3,INF},
                                    {INF,INF,0,2},
                                    {INF,-1,INF,0}
								};

    auto result = floyd_warshall(graph);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result.size();j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}

    return 0;
}