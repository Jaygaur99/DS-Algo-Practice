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
#define rep(i, x, y) for(int i=x; i<y; i++)

// BFS
void printBFS(int **edges, int n, int sv){
    queue<int> pending;
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
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
    delete [] visited;
}

// DFS
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

    cout<<"DFS"<<endl;
    printDFS(edges, n, 0, visited);

    cout<<"BFS"<<endl;
    printBFS(edges, n, 0);

    return 0;
}