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
vi g[N];
int vis[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child : g[curr]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[curr] + 1;
            }
        }  
    }
}


int main()
{
    int n; 
    cin>>n;
    rep(i, 0, n-1){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    cout<<"HI";
    rep(i, 1, n+1){
        cout<<i<<": "<<level[i]<<endl;
    }
    return 0;
}