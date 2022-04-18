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
vi g[N];
int vis[8][8];
int lev[8][8];

int getX(string s){
    return s[0] - 'a';
}

int getY(string s){
    return s[1] - '1';
}

bool isValid(int x, int y){
    return x >= 0 and y >= 0 and x < 8 and y < 8;
}

vii movements = {
    {-1, -2}, {1, 2}, 
    {-1, 2}, {1, -2},
    {2, -1}, {2, 1},
    {-2, -1}, {-2, 1},
};

int bfs(string src, string dest){
    int srcX = getX(src);
    int srcY = getY(src);
    int destX = getX(dest);
    int destY = getY(dest);
    queue<pii> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    lev[srcX][srcY] = 0;

    while(!q.empty()){
        pii v = q.front();
        int x = v.first, y = v.second;
        q.pop();
        
        for(auto movement : movements){
            int childX = movement.first + x;
            int childY = movement.second + y;
            if(!isValid(childX, childY)) continue;
            if(!vis[childX][childY]){
                q.push({childX, childY});
                lev[childX][childY] = lev[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
        if(lev[destX][destY] != INF){
            break;
        }
    }

    return lev[destX][destY];
}

void reset(){
    rep(i, 0, 8){
        rep(j, 0, 8){
            lev[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        reset();
        string s1, s2;
        cin>>s1>>s2;
        cout<<bfs(s1, s2)<<endl;
    }
    
    return 0;
}