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