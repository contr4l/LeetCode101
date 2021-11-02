/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include <stdio.h>
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
    int findMin(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        int res = 0;
        int pos = 0; // twist position
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1]) {
                pos = mid + 1;
                break;
            }
            if (nums[mid] == nums[r]) {
                r--;
            }
            else if (nums[mid] < nums[r]) {
                // 右半区有序递增
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << "pos = " << pos << " && nums[pos] =" << nums[pos] << endl;

        return nums[0] < nums[pos] ? nums[0] : nums[pos];
    }
};
// @lc code=end

