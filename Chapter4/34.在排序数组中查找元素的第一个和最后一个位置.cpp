/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#else
#include "utils.h"
#endif
// @lc code=start
class Solution {
public:
    int my_binary_search(vector< int > nums, int target, int l, int r) {
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        if(my_binary_search(nums, target, l, r) == -1){
            return {-1,-1};
        }

        int tmp = 0;
        vector<int> res;
        while ((tmp = my_binary_search(nums, target, l, r)) != -1){
            r = tmp - 1;
        }
        res.push_back(r+1);
        
        r = nums.size()-1;
        while ((tmp = my_binary_search(nums, target, l, r)) != -1){
            l = tmp +1;
        }
        res.push_back(l-1); 
        return res;
    }
};
// @lc code=end

