/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
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
    int rob(vector<int>& nums) {
        if (nums.size() <= 2)
        {
            auto ret =  max_element(nums.begin(), nums.end());
            return *ret;
        }
        int f1 = nums[0];
        int f2 = max({nums[0], nums[1]});
        int tmp = 0;
        for (int i = 2; i < nums.size(); ++i)
        {
            tmp = f2;
            f2 = max({f1+nums[i], f2});
            f1 = tmp;
        }
        return f2;
    }
};
// @lc code=end

