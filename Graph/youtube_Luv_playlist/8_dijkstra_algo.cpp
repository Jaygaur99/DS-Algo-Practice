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
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vii g[N];

void dijkstra(int source){
    vi dist(N, INF);
    vi vis(N, 0);
    // priority_queue<> pq; can be used too
    set<pii> st;

    st.insert({0, source});
    dist[source] = 0;

    while(st.size() > 0){
        auto node = *st.begin();    
        int v = node.second;
        int distance = node.first;
        
        st.erase(st.begin());
        if(vis[v] == 1)
            continue;

        vis[v] = 1;
        for(auto child : g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int n, m;
    rep(i, 0, m){
        int x, y, wt;
        cin>>x>>y>>wt;
        g[x].push_back({y, wt});
    }

    dijkstra(1);
    return 0;
}