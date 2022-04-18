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

const int N = 1e5, M = 20;
vi gr[N];
int dep[N], Par[N][M];

void dfs(int cur, int par) {
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;

    // calculating the sparse table
    rep(j, 1, M) {
        Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    }

    // rep(j, 1, M){
    //     rep(i, 1, n+1){
    //         parent[i][j] = parent[parent[i][j-1]][j-1];
    //     }
    // }

    for (auto x : gr[cur]) {
        if (x != par) {
            dfs(x, cur);
        }
    }
}

int LCA(int u, int v) {
    if (u == v)
        return u;
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];

    for (int j = M - 1; j >= 0; j--) {
        if ((diff >> j) & 1) {
            // jth bit of diff is set
            u = Par[u][j];
        }
    }
    // u and v are on the same level
    for (int j = M - 1; j >= 0; j--) {
        if (Par[u][j] != Par[v][j]) {
            u = Par[u][j];
            v = Par[v][j];
        }
    }
    return Par[u][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int n;
    cin >> n;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    // find depth
    dfs(1, 0);

    rep(i, 1, 13) {
        cout << i << " -> ";
        rep(j, 0, 4) {
            cout << Par[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}