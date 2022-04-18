#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; i++)

vector<int> getLPS(string pattern)
{
    int len = pattern.length();
    vector<int> lps(len);
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < len)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmpSearch(string text, string pattern)
{
    int lenText = text.length();
    int lenPat = pattern.length();

    int i = 0;
    int j = 0;

    vector<int> lps = getLPS(pattern);

    while (i < lenText and j < lenPat)
    {
        if(text[i] == pattern[j]){
            i++;
            j++;
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    if (j == lenPat){
        return true;
    }
    return false;
}

int main()
{
    string str = "abcxabcdabcdabcy";
    string subString = "abcdabcy";
    cout << kmpSearch(str, subString) << endl;
    return 0;
}