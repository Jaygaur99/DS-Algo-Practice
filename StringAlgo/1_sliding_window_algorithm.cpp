// given text T and pattern P,
// find whether P exists in T or not.
// In case it exists,
// print all the occurences of pattern in text

// example t = codetocode 
// p = code => ans = 0, 7
#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

string T, P;
int lp, lt;

bool match(int l, int r){
    rep(i, 0, lp){
        if(T[l+i] != P[i])
            return false;
    }
    return true;
}

int main()
{
    int t; 
    cin>>t;

    while(t--){
        cin>>T>>P;
        lp = P.size();
        lt = T.size();

        for(int l=0, r=lp-1; r<lt; l++, r++){
            if(match(l, r))
                cout<<l<<" ";
        }
        cout<<endl;
    }

    return 0;
}