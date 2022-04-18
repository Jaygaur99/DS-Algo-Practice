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

class Node{
public:
    string name;
    vector<string> nbrs;
    
    Node(string name){
        this->name = name;
    }
};

class Graph{
    unordered_map<string, Node*> m;

public:
    Graph(vector<string> cities){
        for(string city : cities){
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undir=false){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printAdjList(){
        for(auto cityPair : m){
            auto city = cityPair.first;
            Node *node = cityPair.second;
            cout<<city<<": ";
            for(auto nbr : node->nbrs){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    vector<string> cities = {"Delhi", "Mumbai", "London", "Paris"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("Paris", "London");
    g.addEdge("Delhi", "Mumbai");
    g.addEdge("Paris", "Mumbai");

    g.printAdjList();

    return 0;
}