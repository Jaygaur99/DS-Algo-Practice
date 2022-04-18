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

void printDFS(int **edges, int n, int startingVertex, bool *visited){
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
            printDFS(edges, n, i, visited);
        }
    }
}


void printBFS(int **edges, int n, int sv, bool *visited){
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    while(!pending.empty()){
        int currVertex = pending.front();
        pending.pop();
        cout<<currVertex<<endl;
        for(int i=0; i<n; i++){
            if(i == currVertex)
                continue;
            if(edges[currVertex][i] == 1 && !visited[i]){
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int **edges, int n){
    bool *visited = new bool[n];
    rep(i, 0, n){
        visited[i] = false;
    }
    rep(i, 0, n){
        if(!visited[i])
            printDFS(edges, n, i, visited);
    }
    delete [] visited;
}

void BFS(int **edges, int n){
    bool *visited = new bool[n];
    rep(i, 0, n){
        visited[i] = false;
    }
    rep(i, 0, n){
        if(!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete [] visited;
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

    cout<<"DFS"<<endl;
    DFS(edges, n);

    cout<<"BFS"<<endl;
    BFS(edges, n);

    return 0;
}