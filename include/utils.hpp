#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
void print_vector( vector< T >& g, string S = "") {
    cout << S << " ";
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

template<typename T>
void my_insert_sort(vector<T>&S)
{
    int cnt = 0;
    for (int i = 1; i < S.size(); ++i)
    {
        for (int j = 0; j < i; ++j) {
            if (S[j] > S[i])
            {
                swap(S[j], S[i]);
            }
            cnt++;
        }
        print_vector(S);
    }
    cout << __func__ << " " << cnt << endl;
    return;
}

template<typename T>
void my_bubble_sort(vector<T>&S)
{
    int cnt = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        for (int j = i; j < S.size(); ++j) {
            if (S[j] < S[i]){
                swap(S[j], S[i]);
            }
            cnt++;
        }
        print_vector(S);
    }
    cout << __func__ << " " << cnt << endl;
    return;
}

template < typename T >
void my_selection_sort(vector< T >& S) {
    int tmp = 0;
    int cnt = 0;
    for (int i = 0; i < S.size(); ++i) {
        tmp = i;
        for (int k = i; k < S.size(); k++) {
            if (S[k] < S[tmp]) {
                tmp = k;
            }
            cnt++;
        }
        swap(S[tmp], S[i]);
        print_vector(S);
    }
    cout << __func__ << " " << cnt << endl;
    return;
}

template < typename T >
void merge(vector< T >& S, int l, int mid, int r) {
    vector< T > tmp;
    int i = l, j = mid + 1;
    while (i <= mid || j <= r) {
        if (j > r || S[i] < S[j]) {
            tmp.push_back(S[i]);
            i++;
        }
        else {
            tmp.push_back(S[j]);
            j++;
        }
    }
    for (int i = l; i <= r; i++) {
        S[i] = tmp[i - l];
    }
    return;
}

template < typename T >
void my_merge_sort(vector< T >& S, int l, int r) {
    if (l + 1 >= r) {
        if (S[r] < S[l]) {
            swap(S[l], S[r]);
        }
        return;
    }
    int mid = (l + r) / 2;
    my_merge_sort(S, l, mid);
    my_merge_sort(S, mid + 1, r);
    merge(S, l, mid, r);
    print_vector(S);
    return;
}

template < typename T >
void my_quick_sort(vector< T >& S, int l, int r) {
    int s_l = l, s_r = r;
    if (l >= r) {
        return;
    }
    int pivot = S[l];
    while (l < r) {
        while (l < r && S[r] >= pivot) {
            --r;
        }
        S[l] = S[r];
        while (l < r && S[l] <= pivot) {
            ++l;
        }
        S[r] = S[l];
        
    }
    S[l] = pivot;
    my_quick_sort(S, s_l, l-1);
    my_quick_sort(S, l + 1, s_r);
    print_vector(S);
    return;
}