#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

struct fenwick {
    vector<int> fn;
    int n;
    void init(int n){
        this->n = n + 1; // inclusive // one base indexing (refer video)
        fn.resize(this->n, 0);
    }

    void add(int x, int y){
        x++; // 1 based index
        while(x < n){
            fn[x] += y;
            x += (x & (-x)); // last set bit
        }
    }

    int sum(int x){
        x++;
        int ans = 0;
        while(x){
            ans += fn[x];
            x -= (x & (-x)); // climb to its parent
        }
        return ans;
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    fenwick tree;
    tree.init(v.size());

    for(int i=0; i<v.size(); i++){
        tree.add(i, v[i]);
    }

    cout<<tree.sum(3, 4)<<endl;
    tree.add(4, -3);
    cout<<tree.sum(3, 4)<<endl;
    return 0;
}