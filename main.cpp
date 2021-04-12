// g++ *.cpp *.h -o mergesort.o;./mergesort.o

#include<iostream>
#include<vector>
#include "tests.h"
#include "mergesort_algs.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // test_median();
    // test_bin_search();
    // test_merge_step();
    // test_merge_until();
    test_merge_sort();
    return 0;
}
