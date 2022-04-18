#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
// (a * b) % c;

int multiply(int a, int b, int c){
    int res = 0;
    while(b){
        if(b & 1){
            res += a;
            res %= c;
        }
        a = 2 * a; a %= a;
        b /= 2;
    }
}


int main()
{
    cout << multiply(20, 20, 1e9 + 7);
    return 0;
}