/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
    void search(vector<int>&nums, vector<int>& tmp, vector<int>& visited, vector<vector<int>>&res)
    {
        if (tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == 0)
            {
                if (i > 0 && nums[i] == nums[i-1] && visited[i-1] == 0)
                    continue;

                visited[i] = 1;
                tmp.push_back(nums[i]);
                search(nums, tmp, visited, res);
                tmp.pop_back();
                visited[i] = 0;
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> visited(nums.size(), 0);
        vector<int> tmp;
        search(nums, tmp, visited, ans);
        return ans;
    }
};
// @lc code=end

