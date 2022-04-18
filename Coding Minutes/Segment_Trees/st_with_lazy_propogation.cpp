#include<bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for(int i=m; i<n; i++)

// segment tree for summation
struct segmentTree{
    int n;
    vector<int> st, lazy;
    
    segmentTree(int n){
        this->n = n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
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
        
        // Lazy propogation
        if(lazy[node] != 0){
            // pending updates 
            // update the segment tree node 
            st[node] += lazy[node] * (end - start + 1);

            if(start != end){
                // propogate the updateed value to children
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

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

    void update(int start, int end, int node, int l, int r, int value){
        if(start > r or end < l)
            return;

        if(lazy[node] != 0){
            // pending updates 
            // update the segment tree node 
            st[node] += lazy[node] * (end - start + 1);

            if(start != end){
                // propogate the updateed value to children
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // complete overlap
        if(start >= l and end <= r){
            st[node] += value * (end - start + 1);
            if(start != end){
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        // Partial Overlap
        int mid = start + (end - start) / 2;
        update(start, mid, 2*node + 1, l, r, value);
        update(mid+1, end, 2*node + 2, l, r, value);

        st[node] = st[2*node + 1] + st[2 * node + 2];
        return;
    }

    void build(vector<int> &v){
        build(0, n-1, 0, v);
    }

    int query(int l, int r){
        return query(0, n-1, l, r, 0);
    }

    void update(int l, int r, int x){ // from l to r update it to x
        update(0, n-1, 0, l, r, x);
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    // cout<<v.size();
    segmentTree tree(v.size());
    tree.build(v);
    for(int i=0; i<16; i++)
        cout<<tree.st[i]<<" ";
    // cout << tree.query(0, 4) << endl;
    cout<<endl;
    tree.update(4, 6, 10);
    for(int i=0; i<16; i++)
        cout<<tree.st[i]<<" ";
    cout<<endl;
    cout << tree.query(0, 9) << endl;
    for(int i=0; i<16; i++)
        cout<<tree.st[i]<<" ";
 
    // cout << tree.query(4, 4) << endl;

    return 0;
}