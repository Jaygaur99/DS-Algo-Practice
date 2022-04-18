#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
/* input -> 
7 8
1 2
2 3 
1 3
2 4
4 5
5 6
6 7
4 7
    */

const int N = 1e5;
vector<int> adj[N];
int vis[N], discovered[N], lowest[N], tme=1; // time
vector<pair<int, int>> bridges;
set<int> arti_pts;

void dfs(int curr, int par){
    vis[curr] = 1;
    discovered[curr] = lowest[curr] = tme++;
    int child = 0;

    for(auto x : adj[curr]){
        if(!vis[x]){
            dfs(x, curr);
            child++;
            // we know low and disc of x
            lowest[curr] = min(lowest[curr], lowest[x]);

            // bridges
            if(lowest[x] > discovered[curr]){
                bridges.push_back({curr, x});
            }
            // articulation points
            if(par != 0 and lowest[x] >= discovered[curr]){
                arti_pts.insert(curr);
            }

        } else if (x != par) { 
            // backedge
            lowest[curr] = min(lowest[curr], discovered[x]);
        }
    }

    // root is an arti or not
    if(par == 0 and child > 1){
        arti_pts.insert(curr);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    rep(i, 0, m){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    // print arti
    for(auto x : arti_pts)
        cout<<x<<"\n";
    cout<<endl;
    // print bridges
    for(auto x : bridges)
        cout<<x.first<<" "<<x.second<<"\n";

    return 0;
}