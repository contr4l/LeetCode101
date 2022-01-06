/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
    vector<int> tmp_l;
    vector<int> visited;
    vector<vector<int>> res;
    void search(vector<int>& nums, int k, int tmp, int target)
    {
        if (tmp == target)
        {
            res.push_back(tmp_l);
            return;
        }

        if (tmp > target)
        {
            return;
        }

        for (int i = k; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i]==nums[i-1] && visited[i-1] == 0)
                continue;
            visited[i] = 1;
            tmp_l.push_back(nums[i]);
            search(nums, i+1, tmp+nums[i], target);
            tmp_l.pop_back();
            visited[i] = 0;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        visited.resize(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        search(candidates, 0, 0, target);
        return res;
    }
};
// @lc code=end

