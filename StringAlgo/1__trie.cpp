#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

int cnt = 0;

struct node {
    node *nxt[26];
    bool isEnd;
    node() {
        isEnd = false;
        rep(i, 0, 26)
            nxt[i] = NULL;
        cnt++;
    }
};

node *root;

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

bool search_trie(string s){
    node *curr = root;
    rep(i, 0, s.size()){
        int mp = s[i] - 'a';
        if(curr->nxt[mp] == NULL) return false;
        curr = curr->nxt[mp];
    }
    return curr->isEnd;
}

int main()
{
    int n;
    cin>>n;

    root = new node();

    rep(i, 0, n){
        string s;
        cin>>s;
        insert_trie(s);
    }
    bool ans = search_trie("apaar");
    if(ans){
        cout<<"FOUND";
    } else {
        cout<<"NOT FOUND";
    }
    return 0;
}

/*
input:
5
apaar
prateek
jatin
apurv
abhas
*/
