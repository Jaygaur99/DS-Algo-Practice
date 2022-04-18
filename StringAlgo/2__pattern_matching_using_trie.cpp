#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

struct node {
    node *nxt[26];
    bool isEnd;
    node() {
        isEnd = false;
        rep(i, 0, 26)
            nxt[i] = NULL;
    }
};

node *root;

// Insert in O(N^2)
void insert_trie(string s){
    node *curr = root;
    rep(i, 0, s.size()){
        int mp = s[i] - 'a';
        // never been explored
        if(curr->nxt[mp] == NULL) {  
            curr->nxt[mp] = new node();
        }
        // go to that node
        curr = curr->nxt[mp];
    }

    curr->isEnd = true;
}


// Searching in O(pat)
bool search_trie(string s){
    node *curr = root;
    rep(i, 0, s.size()){
        int mp = s[i] - 'a';
        if(curr->nxt[mp] == NULL) return false;
        curr = curr->nxt[mp];
    }
    return true;
}

int main()
{
    root = new node();

    string text = "ababba";
    string pat = "aba";

    int n = text.size();
    rep(i, 0, n){
        insert_trie(text.substr(i));
    }
    
    if(search_trie(pat)){
        cout<<"Found";
    } else {
        cout<<"Not Found";
    }


    return 0;
}
