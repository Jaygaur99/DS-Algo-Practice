#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
#define int long long int

int poly_hash(string s) {
    int hash = 0, prime=31, mod = 1e9 + 7 ;
    int p_power = 1;
    rep(i, 0, s.size()){
        hash += (s[i] - 'a' + 1) * p_power;
        p_power *= prime;
        hash %= mod;
        p_power %= mod;
    }
    return hash;
}

int32_t main()
{
    string s = "abaasdfasdfasdfasdfasdfasdfasdfasdwerwerbababa";
    cout<<poly_hash(s)<<endl;
    return 0;
}