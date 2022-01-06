/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */
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
    int count(int len_)
    {
        if (len_ < 3)
        {
            return 0;
        }
        return (1 + (len_ - 2)) * (len_ - 2) / 2;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int start = 2;
        int len_ = 2;
        int ans = 0;
        while (start < nums.size())
        {
            if (nums[start - 1] * 2 == nums[start] + nums[start - 2])
            {
                start++;
                len_++;
            }
            else {
                ans += count(len_);
                start += 1;
                len_ = 2;
            }
        }
        ans += count(len_);
        return ans;
    }
};
// @lc code=end

