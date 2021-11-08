/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
    void search(vector<int> &nums, vector<int> &tmp, vector<int> &visited, vector<vector<int>> &res)
    {
        if (tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 0)
            {
                tmp.push_back(nums[i]);
                visited[i] = 1;
                search(nums, tmp, visited, res);
                visited[i] = 0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> visited(nums.size(), 0);
        vector<int>tmp;
        search(nums, tmp, visited, res);
        return res;
    }
};
// @lc code=end

