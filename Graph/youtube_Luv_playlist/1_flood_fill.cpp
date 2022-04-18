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
// bool vis[N];
// vi g[N];

// https://leetcode.com/problems/flood-fill/
void dfs(int i, int j, int initialColor, int newColor, vvi &image){
    int n = image.size();
    int m = image[0].size();
    if(i < 0 or j < 0 or i >= n or j >= n) return;
    if(image[i][j] != initialColor) return;

    image[i][j] = newColor;

    dfs(i-1, j, initialColor, newColor, image);
    dfs(i+1, j, initialColor, newColor, image);
    dfs(i, j-1, initialColor, newColor, image);
    dfs(i, j+1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int initialColor = image[sr][sc];
    if(initialColor != newColor)
        dfs(sr, sc, initialColor, newColor, image);
    return image;
}

int main()
{
    
    return 0;
}