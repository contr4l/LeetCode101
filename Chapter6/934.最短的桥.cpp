/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */
#ifndef LC_TEST
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& visited, int prev, int after, int final)
    {
        queue<pair<int, int>> tmp;
        int row = grid.size(), col = grid[0].size();
        int pos[] = { 1, 0, -1, 0, 1 };
        int cnt = 0;
        while(visited.size() > 0 || tmp.size() > 0)
        {
            if (visited.size() == 0)
            {
                cnt++;
                swap(visited, tmp);
                // printf("size after swap: %lu %lu.\n", visited.size(), tmp.size());
            }
            auto p = visited.front();
            visited.pop();
            for (int i = 0; i < 4; ++i)
            {
                int ni = p.first + pos[i], nj = p.second + pos[i + 1];
                if (ni < 0 || ni >= row || nj < 0 || nj >= col)
                    continue;
                if (grid[ni][nj] == prev)
                {
                    grid[ni][nj] = after;
                    tmp.push({ ni, nj });
                }
                else if (grid[ni][nj] == final)
                {
                    return cnt;
                }
            }
        }
        return 0;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        // 从一座岛的每一个位置BFS，到达另一座岛时记录长度
        queue<pair<int, int>> visited;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] != 0)
                {
                    grid[i][j] = 2;
                    visited.push({i,j});
                    break;
                }
            }
            if (visited.size() > 0)
                break;
        }
        bfs(grid, visited, 1, 2, -1);
        // print_vec(grid);
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                {
                    visited.push({i,j});
                }
            }
        }
        int ret = bfs(grid, visited, 0, 2, 1);
        return ret;
    }
};
// @lc code=end
