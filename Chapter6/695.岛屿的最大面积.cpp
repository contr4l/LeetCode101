/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面�?
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
    int dfs(int i, int j, vector< vector< int > >& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }
        if (grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(i + 1, j, grid) + dfs(i - 1, j, grid)
               + dfs(i, j + 1, grid) + dfs(i, j - 1, grid);
    }
    int maxAreaOfIsland(vector< vector< int > >& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(i, j, grid));
                }
            }
        }
        return res;
    }
};
// @lc code=end

