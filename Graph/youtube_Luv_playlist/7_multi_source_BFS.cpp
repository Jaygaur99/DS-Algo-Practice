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
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int val[N][N];
int vis[N][N];
int lev[N][N];
int n, m;
// https://www.codechef.com/problems/SNSOCIAL
// https://www.youtube.com/watch?v=xvi8PqRrAyU&list=PLauivoElc3ghxyYSr_sVnDUc_ynPk6iXE&index=15
// code is wrong somewhere
void reset(){
    rep(i, 0, n){
        rep(j, 0, m){
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}

vii movements = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, 
    {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
};

bool isValid(int i, int j){
    return i >= 0 and j >= 0 and i < n and j < n;
}

int bfs(){
    int mx = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            mx = max(mx, val[i][j]);
        }
    }
    queue<pii> q;
    rep(i, 0, n){
        rep(j, 0, m){
            if(mx == val[i][j]){
                q.push({i, j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();

        for(auto movement : movements){
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if(!isValid(child_x, child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x, child_y});
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            vis[child_x][child_y] = 1;

            ans = max(ans, lev[child_x][child_y]);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        reset();
        rep(i, 0, n){
            rep(j, 0, m){
                cin>>vis[i][j];
            }
        }
        cout<<bfs()<<endl;
    }
    return 0;
}