#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)
vector<int> z;
int cnt = 0;

void z_function(string s){
    int l=0, r=0;
    int n = s.size();

    rep(i, 1, n){
        if(i > r){
            l = i; r = i;
            while(r < n and s[r-l] == s[r]){
                r++;
            }
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if(z[k] <= r-i){
                z[i] = z[k];
            } else {
                l = i;
                while(r < n and s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

void searchString(string text, string pattern){
    string str = pattern + "#" + text;
    int n = str.length();
    z.resize(n);
    z_function(str);
    rep(i, 0, n){
        if(z[i] == pattern.length()){
            cout<<i - pattern.length() - 1 <<endl;
            cnt++;
        }
    }
}


vector<int> z_function2(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    string text="abcdsafbcdfasbcda";
    string pattern = "bcd";
    searchString(text, pattern);
    cout<<cnt;
    return 0;
}