#include<iostream>
#include<vector>
#include "mergesort_algs.h"
using namespace std;


void test_median()
{
    cout << "Testing Median, Should all be 5:\n";
    vector<int> v = {1,23,5};
    cout << v[median(v,0,2)] << "\n";
    v = {1,5,23};
    cout << v[median(v,0,2)] << "\n";
    v = {23,5,1};
    cout << v[median(v,0,2)] << "\n";
    v = {23,5,1};
    cout << v[median(v,0,2)] << "\n";
    v = {5,23,1};
    cout << v[median(v,0,2)] << "\n";
    v = {5,1,23};
    cout << v[median(v,0,2)] << "\n";

}

void test_bin_search()
{
    cout << "\nTesting Binary Search, groups should all match";
    vector<int> v = {4,7,12,29};
    show_vec(v,0,v.size()-1);
    cout << "0\n";
    cout << bin_search(v,0,v.size()-1,3) << "\n";
    cout << bin_search(v,0,v.size()-1,4) << "\n";
    cout << "\n1\n";
    cout << bin_search(v,0,v.size()-1,5) << "\n";
    cout << bin_search(v,0,v.size()-1,7) << "\n";
    cout << "\n2\n";
    cout << bin_search(v,0,v.size()-1,8) << "\n";
    cout << bin_search(v,0,v.size()-1,12) << "\n";
    cout << "\n3\n";
    cout << bin_search(v,0,v.size()-1,13) << "\n";
    cout << bin_search(v,0,v.size()-1,29) << "\n";
    cout << "\n4\n";
    cout << bin_search(v,0,v.size()-1,30) << "\n";
    v.push_back(100);
    show_vec(v,0,v.size()-1);
    cout << "0\n";
    cout << bin_search(v,0,v.size()-1,3) << "\n";
    cout << bin_search(v,0,v.size()-1,4) << "\n";
    cout << "\n1\n";
    cout << bin_search(v,0,v.size()-1,5) << "\n";
    cout << bin_search(v,0,v.size()-1,7) << "\n";
    cout << "\n2\n";
    cout << bin_search(v,0,v.size()-1,8) << "\n";
    cout << bin_search(v,0,v.size()-1,12) << "\n";
    cout << "\n3\n";
    cout << bin_search(v,0,v.size()-1,13) << "\n";
    cout << bin_search(v,0,v.size()-1,29) << "\n";
    cout << "\n4\n";
    cout << bin_search(v,0,v.size()-1,30) << "\n";
    cout << bin_search(v,0,v.size()-1,100) << "\n";
    cout << "\n5\n";
    cout << bin_search(v,0,v.size()-1,101) << "\n";
}

// void test_merge_step()
// {
//     vector<int> v;
//     vector<int> rem;

//     v = {4,6,8,5,7,9};
//     show_vec(v,0,v.size());
//     rem = merge_step(v,0,3,v.size());
//     show_vec(rem,0,rem.size());
//     // { 2, 5 }
//     show_vec(v,0,v.size());
//     // { 4, 6, 5, 7, 8, 9 }
//     cout << "\n\n";

//     v = {4,6,8,11,5,7,9,11,13};
//     show_vec(v,0,v.size());
//     rem = merge_step(v,0,4,v.size());
//     show_vec(rem,0,rem.size());
//     // { 3, 7 }
//     show_vec(v,0,v.size());
//     // { 4, 6, 8, 5, 7, 9, 11, 11, 13 }
//     cout << "\n\n";

//     v = {4,6,8,11,13,5,7,9,11,13};
//     show_vec(v,0,v.size());
//     rem = merge_step(v,0,5,v.size());
//     show_vec(rem,0,rem.size());
//     // { 3, 8 }
//     show_vec(v,0,v.size());
//     // { 4, 6, 8, 5, 7, 9, 11, 13, 11, 13 }
//     cout << "\n\n";

//     v = {11,13,5,7,9,11,13};
//     show_vec(v,0,v.size());
//     rem = merge_step(v,0,2,v.size());
//     show_vec(rem,0,rem.size());
//     // { 0, 5 }
//     show_vec(v,0,v.size());
//     // { 5, 7, 9, 11, 13, 11, 13 }
//     cout << "\n\n";
// }
void test_merge_until()
{
    vector<int> v;

    v = {4,6,8,5,7,9};
    show_vec(v);
    merge_until(v,0,3,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {1,4,6,8,5,7,9};
    show_vec(v);
    merge_until(v,0,4,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {4,6,8,5,6,7,9};
    show_vec(v);
    merge_until(v,0,3,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {1,3,4,6,8,2,5,7,9};
    show_vec(v);
    merge_until(v,0,5,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    show_vec(v);
    merge_until(v,0,0,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {5, 8, 1, 2, 3, 4, 6, 7, 9};
    show_vec(v);
    merge_until(v,0,2,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {1, 4, 9, 2, 3, 5, 6, 7, 8};
    show_vec(v);
    merge_until(v,0,3,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {1, 5, 7, 8, 2, 3, 4, 6, 9};
    show_vec(v);
    merge_until(v,0,4,v.size());
    show_vec(v);
    cout << "\n\n";
    
    v = {1, 2, 5, 7, 9, 3, 4, 6, 8};
    show_vec(v);
    merge_until(v,0,5,v.size());
    show_vec(v);
    cout << "\n\n";

    v = {9, 1, 2, 3, 4, 5, 6, 7, 8};
    show_vec(v);
    merge_until(v,0,1,v.size());
    show_vec(v);
    cout << "\n\n";
    
    v = {2, 3, 4, 5, 6, 7, 8, 9, 1};
    show_vec(v);
    merge_until(v,0,8,v.size());
    show_vec(v);
    cout << "\n\n";

}

void test_merge_sort()
{
    vector<vector<int>> vs;
    vs.push_back( {2, 3, 4, 5, 6, 7, 8, 9, 1} );
    vs.push_back( {0, 2, 3, 4, 5, 6, 7, 8, 9, 1} );
    vs.push_back( {9, 1, 2, 3, 4, 5, 6, 7, 8} );
    vs.push_back( {1, 2, 5, 7, 9, 3, 4, 6, 8} );
    vs.push_back( {1, 5, 7, 8, 2, 3, 4, 6, 9} );
    vs.push_back( {1, 4, 9, 2, 3, 5, 6, 7, 8} );
    vs.push_back( {5, 8, 1, 2, 3, 4, 6, 7, 9} );
    vs.push_back( {1, 2, 3, 4, 5, 6, 7, 8, 9} );
    vs.push_back( {2, 6, 8, 5, 3, 1, 4, 7, 9} );
    vs.push_back( {2, 4, 3, 7, 1, 6, 9, 8, 5} );
    vs.push_back( {3, 8, 9, 2, 6, 1, 5, 7, 4} );
    vs.push_back( {4, 7, 8, 3, 6, 1, 9, 2, 5} );
    vs.push_back( {4, 6, 2, 5, 3, 8, 1, 9, 7} );
    vs.push_back( {3,2,1} );
    vs.push_back( {2,1,3} );
    vs.push_back( {3,1,2} );
    vs.push_back( {5,2,1,3} );
    vs.push_back( {3,2,1,4} );
    vs.push_back( {3,1,2,4} );
    vs.push_back( {3,1,2,4,0} );
    vs.push_back( {3,1,2,4,1,7} );
    vs.push_back( {3,1,2,4,1,7,9} );
    vs.push_back( {3,1,2,4,1,7,9,1} );
    vs.push_back( {3,1,2,4,1,7,9,1,17} );

    for (auto v:vs)
    {
        show_vec(v);
        merge_sort(v);
        show_vec(v);
        cout << "\n\n";
    }
}

    // v.push_back(13);
