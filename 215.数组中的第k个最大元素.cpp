/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <functional>
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
class Solution {
public:
    // 维护一个size=k的小顶堆，堆顶最小，当进入一个新数时，先和堆顶比较
    // 若比堆顶小，则丢弃（由于存在k个比p大的数）
    // 若比堆顶大，替换堆顶，然后重新建堆
    void head_insert(vector<int>& heap, int p)
    {
        if (p > heap[0]){
            heap[0] = p;
            rebuild_heap(heap, 0); 
        }
    }
    void rebuild_heap(vector< int >& heap, int start) {
        int n = start;
        int l = 2 * n + 1, r = 2 * n + 2;
        while (l < heap.size() && r < heap.size()) {
            if (heap[n] <= heap[l] && heap[n] <= heap[r]) {
                return;
            }
            else if (heap[l] <= heap[r]) {
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
        if (l < heap.size() && heap[n] > heap[l]) {
            swap(heap[n], heap[l]);
        }
    }

    void build_heap(vector< int >& S) {
        int i = S.size() - 1;
        int p = (i + 1) / 2 - 1;
        // cout << i << " " << p << endl;
        // cout << S[i] << " vs " << S[p] << endl;
        while (i > 0 && S[i] < S[p]) {
            swap(S[i], S[p]);
            i = p;
            p = (i + 1) / 2 - 1;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        vector<int>heap;
        heap.push_back(nums[0]);
        int i = 1;
        while (heap.size() < k)
        {
            heap.push_back(nums[i++]);
            build_heap(heap);
            // print_vector(heap);
        }

        while (i < nums.size()) {
            head_insert(heap, nums[i++]);
            #ifdef LC_TEST
            print_vector(heap);
            #endif
        }
        return heap[0];
    }
};
// @lc code=end
#ifdef LC_TEST
int main()
{
    Solution A;
    vector<int> nums{3,2,1,5,6,4};
    A.findKthLargest(nums, 2);
    return 0;
}
#endif
