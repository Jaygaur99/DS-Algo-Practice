// Coding Ninjas Competitive Programming
#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

vector<int> getLPS(string pattern){
    int len = pattern.length();
    vector<int> lps(len);

    lps[0] = 0;
    int i=1, j=0;
    while(i < len){
        if(pattern[i] == pattern[j]){
            lps[i] = j+1;
            i++;
            j++;
        } else {
            if (j != 0){
                j = lps[j-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    } 
}

int main()
{
    
    return 0;   
}