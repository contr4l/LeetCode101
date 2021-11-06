/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        int zero = nums.size();
        int ones = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0 && zero == nums.size())
            {
                zero = i;
                break;
            }
        }
        zero = quick_sort(nums, 0, nums.size()-1, zero);

        int l = nums.size();
        for (int i = zero+1; i<nums.size();i++)
        {
            if (nums[i] != 0 && l == nums.size()){
                l = i;
            }
            if (nums[i] == 1 && ones == nums.size())
            {
                ones = i;
                break;
            }
        }
        quick_sort(nums, l, nums.size()-1, ones);
    }

    int quick_sort(vector<int> &nums, int l, int r, int pivot)
    {
        if (l >= nums.size() || pivot >= nums.size()) return -1;
        int target = nums[pivot];
        while (l < r)
        {
            while (l < r && nums[r] > target)
            {
                r--;
            }
            if (l != r)
            {
                swap(nums[pivot], nums[r]);
                pivot = r;
            }

            while (l < r && nums[l] <= target)
            {
                l++;
            }
            swap(nums[pivot],nums[l]);
            pivot = l;
        }
        nums[l] = target;
        return l;
    }
};
// @lc code=end

