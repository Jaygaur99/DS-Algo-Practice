#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
const int mod = 1e9+7;

// O(log(b))
int power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res *= a; res %= mod;
        a *= a; a %= mod;
        b /= 2; // b /= 2
    }
    return res;
}

int main()
{
    cout << power(2, 10);
    return 0;
}