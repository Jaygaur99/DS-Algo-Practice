#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pdbs;

int main()
{
    pdbs ord_set; // Declaration

    // Insertion
    ord_set.insert(1);
    ord_set.insert(2);
    ord_set.insert(3);
    ord_set.insert(4);
    ord_set.insert(5);

    // Printing
    cout<< " Ordered_set = ";
    for(auto i : ord_set)
        cout<<i<<" ";
    cout<<endl;

    // Finding kth element by index
    cout<<" 0th :"<< *ord_set.find_by_order(0)<<endl; // log(n)

    // Number smaller than 3
    cout<< ord_set.order_of_key(3)<<endl; // 1 2 3 4 5

    // erase
    ord_set.erase(4);

    // Printing
    cout<< " Ordered_set = ";
    for(auto i : ord_set)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}