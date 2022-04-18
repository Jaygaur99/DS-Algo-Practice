#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

class Graph{
    int V;
    vector<int> *adj;

    // a simple dfs to fill order in the stack
    void fillorder(int v, bool visited[], stack<int>& s){
        visited[v] = true;
        for(auto i : adj[v]){
            if(!visited[i]){
                fillorder(i, visited, s);
            }
        }
        s.push(v);
    }

    void DFSUtil(int v, bool visited[]){
        visited[v] = true;
        cout<<v<<" ";
        
        for(auto v : adj[v]){
            if(!visited[v])
                DFSUtil(v, visited);
        }
    }

public:
    Graph(int v){
        this->V = v;
        adj = new vector<int>[V];
    }
    
    void addEdge(int v, int w){
        adj[v].push_back(w); 
    }

    Graph getTranspose(){
        Graph g(V);
        rep(v, 0, V){
            for(auto i : adj[v]){
                g.adj[i].push_back(v);
            }
        }
        return g;
    }

    void printSCCs(){
        stack<int> s;
        bool *visited = new bool[V];
        rep(i, 0, V){
            visited[i] = false;
        }
        // fill order in the stack
        rep(i, 0, V){
            if(visited[i] == false)
                fillorder(i, visited, s);
        }

        // now get the transpose of the graph
        Graph gr = getTranspose();

        // again put false in visited
        rep(i, 0, V){
            visited[i] = false;
        }

        // now apply dfs to get the ans i.e. strongly connected components
        while(!s.empty()){
            int v = s.top();
            s.pop();

            if(!visited[v]){
                gr.DFSUtil(v, visited);
                cout<<endl;
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout<<"Following are the strongly connected components in the given graph: \n";
    g.printSCCs();
    return 0;
}