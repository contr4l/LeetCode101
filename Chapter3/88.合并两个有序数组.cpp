/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#ifndef LC_TEST
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
class Solution {
public:
    void merge(vector< int >& nums1, int m, vector< int >& nums2, int n) {
        for (int i = m+n-1; i >= n; i--)
        {
            swap(nums1[i-n], nums1[i]);
        }
        #ifdef LC_TEST
        print_vector(nums1);
        print_vector(nums2);
        #endif
        
        int curr1 = n, curr2 = 0;
        while (curr1 < m+n && curr2 < n) {
            if (nums1[curr1] <= nums2[curr2]) {
                nums1[curr1+curr2-n] = nums1[curr1];
                curr1++;
            }
            else {
                nums1[curr1+curr2-n] = nums2[curr2];
                curr2++;
            }
            #ifdef LC_TEST
            print_vector(nums1);
            #endif
        }
        while (curr2 < n){
            nums1[curr1+curr2-n] = nums2[curr2];
            curr2++;
            #ifdef LC_TEST
            print_vector(nums1);
            #endif
        }
    }
};
// @lc code=end

#ifdef LC_TEST
int main()
{
    Solution A;
    vector<int> nums1{1,2,4,5,6,0};
    vector<int> nums2{3};
    A.merge(nums1, 5, nums2, 1);
    return 0;
}
#endif