/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
class Solution
{
public:
    void bfs(vector<vector<char>> &grid, queue<pair<int, int>> &visited)
    {
        int pos[] = { -1, 0, 1, 0, -1 };
        while (visited.size() > 0)
        {
            auto p = visited.front();
            visited.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ni = p.first + pos[i];
                int nj = p.second + pos[i + 1];
                if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size())
                    continue;
                if (grid[ni][nj] == 'O')
                {
                    grid[ni][nj] = 'A';
                    visited.push({ ni, nj });
                }
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        queue<pair<int, int>> visited;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1)
                {
                    if (board[i][j] == 'O')
                    {
                        visited.push({ i, j });
                        board[i][j] = 'A';
                        bfs(board, visited);
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end

