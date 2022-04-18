#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

// DFS
void printGraph(int **edges, int n, int startingVertex, bool *visited){
    cout << startingVertex << endl;
    visited[startingVertex] = true;
    rep(i, 0, n){
        if(i == startingVertex){
            continue;
        }
        if(edges[startingVertex][i] == 1){
            if(visited[i]){
                continue;
            }
            printGraph(edges, n, i, visited);
        }
    }
}

int main()
{
    int n, e;
    cin>>n>>e;
    int ** edges = new int*[n];
    rep(i, 0, n){
        edges[i] = new int[n];
        rep(j, 0, n){
            edges[i][j] = 0;
        }
    }
    
    rep(i, 0, e){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    rep(i, 0, n){
        visited[i] = false;
    }

    printGraph(edges, n, 0, visited);
    return 0;
}