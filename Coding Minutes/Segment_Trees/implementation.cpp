#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

// segment tree for summation
struct segmentTree{
    int n;
    vector<int> st;
    
    segmentTree(int n){
        this->n = n;
        st.resize(4 * n, 0);
    }
    
    void build(int start, int end, int node, vector<int> &v){
        // leaf node
        if(start == end){
            st[node] = v[start];
            return;
        }

        int mid = start + (end - start) / 2;
        // left subtree is (start, mid)
        build(start, mid, 2 * node + 1, v);
        // right subtree is (mid + 1, end)
        build(mid+1, end, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    int query(int start, int end, int l, int r, int node){
        // non overlapping case
        if(start > r || end < l) return 0;

        // complete overlap
        if(start >= l and end <= r){
            return st[node];
        }

        // partial overlap case
        int mid = start + (end - start) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return q1 + q2;
    }

    void update(int start, int end, int node, int index, int value){
        // base case
        if(start == end){
            st[node] = value;
            return;
        }
        
        int mid = start + (end - start) / 2;
        if(index <= mid){
            update(start, mid, 2 * node + 1, index, value);
        } else {
            update(mid + 1, end, 2 * node + 2, index, value);
        }
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
        return;
    }

    void build(vector<int> &v){
        build(0, n-1, 0, v);
    }

    int query(int l, int r){
        return query(0, n-1, l, r, 0);
    }

    void update(int x, int y){ // on index x update it to y
        update(0, n-1, 0, x, y);
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    // cout<<v.size();
    segmentTree tree(v.size());
    tree.build(v);
    // for(int i=0; i<8; i++)
    //     cout<<tree.st[i]<<" ";
    cout << tree.query(0, 4) << endl;
    tree.update(4, 10);
    cout << tree.query(2, 6) << endl;
    cout << tree.query(4, 4) << endl;

    return 0;
}