#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
#define int long long int

int p = 31;
int mod = 1e9 + 7;

int powr(int a, int b){
    // a ^ b % mod
    int res = 1;
    while(b) {
        if (b & 1) res *= a;
        b /= 2;
        a *= a;
        a %= mod;
        res %= mod; 
    }
    return res;
}

int inv(int x){
    return powr(x, mod-2);
}

int poly_hash(string s) {
    int hash = 0;
    int p_power = 1;
    rep(i, 0, s.size()){
        hash += (s[i] - 'a' + 1) * p_power;
        p_power *= p;
        hash %= mod;
        p_power %= mod;
    }
    return hash;
}

int32_t main()
{
    string text = "abacddesbaba";
    string pat = "aba";
    int n = text.size(), m = pat.size();
    
    int pat_hash = poly_hash(pat);
    int text_hash = poly_hash(text.substr(0, m));

    if(pat_hash == text_hash){
        cout<<0<<"\n";
    }
    
    for(int i=1; i+m<=n; i++){
        text_hash = (text_hash - (text[i-1] - 'a' + 1) + mod) % mod;
        text_hash = (text_hash * inv(p)) % mod;
        text_hash = text_hash + (text[i+m-1] - 'a' + 1) * powr(p, m-1);
        text_hash %= mod;

        if(text_hash == pat_hash){
            cout<<i<<"\n";
        }
    }

    return 0;
}