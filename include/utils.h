#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
void print_vector( vector< T >& g ) {
    for ( auto i : g ) {
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void print_vec_vec( vector< vector<T> >& g ) {
    for ( vector<T> p : g ) {
        cout << "[ ";
        for (auto i : p) {
            cout << i << ",  ";
        }
        cout << "]\n";
    }
    cout << endl;
}

template < typename T >
int binary_search(vector< T >& S, T target) {
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] > S[i + 1]) {
            cout << "vector must be accending, exit -1.\n";
            return -1;
        }
    }

    int search_cnt = 0;

    int l = 0, r = S.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (S[mid] == target) {
            printf("search %d times.\n", search_cnt);
            return mid;
        }
        else if (S[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
        search_cnt++;
    }
    printf("search %d times.\n", search_cnt);
    return -1;
}