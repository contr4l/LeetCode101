/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < n; ++i)
        {
            grid[0][i] = grid[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; ++i)
        {
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                grid[i][j] = min({ grid[i - 1][j], grid[i][j - 1] }) + grid[i][j];
            }
        }
        return  grid[m-1][n-1];
    }
};
// @lc code=end

