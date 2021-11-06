/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
class Solution {
public:
    unordered_map<int, int>cnt;

    void head_insert(vector<int>& heap, int p)
    {
        if (cnt[p] > cnt[heap[0]]){
            heap[0] = p;
            rebuild_heap(heap, 0); 
            #ifdef LC_TEST
            print_vector(heap);
            #endif
        }
    }
    void rebuild_heap(vector< int >& heap, int start) {
        int n = start;
        int l = 2 * n + 1, r = 2 * n + 2;
        while (l < heap.size() && r < heap.size()) {
            if (cnt[heap[n]] <= cnt[heap[l]] && cnt[heap[n]] <= cnt[heap[r]]) {
                return;
            }
            else if (cnt[heap[l]] <= cnt[heap[r]]) {
                swap(heap[l], heap[n]);
                n = l;
            }
            else {
                swap(heap[r], heap[n]);
                n = r;
            }
            l = 2 * n + 1;
            r = 2 * n + 2;
        }
        if (l < heap.size() && cnt[heap[n]] > cnt[heap[l]]) {
            swap(heap[n], heap[l]);
        }
    }

    void build_heap(vector< int >& S) {
        int i = S.size() - 1;
        int p = (i + 1) / 2 - 1;
        // cout << i << " " << p << endl;
        // cout << S[i] << " vs " << S[p] << endl;
        while (i > 0 && cnt[S[i]] < cnt[S[p]]) {
            swap(S[i], S[p]);
            i = p;
            p = (i + 1) / 2 - 1;
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> elems;
        for (auto i : nums) {
            cnt[i]++;
            if (cnt[i] == 1) {
                elems.push_back(i);
            }
        }
        if (elems.size() < k) {
            return elems;
        }
        #ifdef LC_TEST
        print_vector(elems);
        #endif
        /* 堆排序 */
        /*********
        vector< int > heap;
        int i = 0;
        for (; i < k; ++i) {
            heap.push_back(elems[i]);
            build_heap(heap);
        }
        #ifdef LC_TEST
        print_vector(heap);
        #endif
        while (i < elems.size()) {
            head_insert(heap, elems[i++]);
        }
        return heap;
        *********/
        /* 桶排序 */
        unordered_map< int, vector< int > > bukket;
        int max_cnt = 0;
        for (auto i : cnt) {
            bukket[i.second].push_back(i.first);
            if (i.second > max_cnt)
                max_cnt = i.second;
        }
        vector< int > res;
        while (max_cnt > 0) {
            if (bukket[max_cnt].size() != 0) {
                for (auto i : bukket[max_cnt]) {
                    res.push_back(i);
                }
            }
            if (res.size() == k)
                return res;
            max_cnt--;
        }
        return res;
    }
};
// @lc code=end
#ifdef LC_TEST
int main()
{
    Solution A;
    vector<int> nums{1,1,1,2,2,3};
    A.topKFrequent(nums, 2);
    return 0;
}
#endif
