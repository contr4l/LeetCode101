/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
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
class Solution {
public:
    int bfs(vector<vector<int>>&mat)
    {
        int dist = 0;
        vector<int> tmp(mat[0].size(), 0);
        vector<vector<int>> visited(mat.size(), tmp);
        queue<pair<int, int>> q;
        queue<pair<int, int>> tq;
        q.push({0,0});
        while (q.size() || tq.size()) {
            if (q.size() == 0)
            {
                dist++;
                swap(q, tq);
            }
            auto p = q.front();
            q.pop();
            visited[p.first][p.second] = 1;
            if (mat[p.first][p.second] == 0)
                return dist;
            if (p.first + 1 < mat.size() && visited[p.first + 1][p.second] == 0)
                tq.push({ p.first + 1, p.second });
            if (p.second + 1 < mat[0].size() && visited[p.first][p.second + 1] == 0)
                tq.push({ p.first, p.second + 1 });
        }
        return dist;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> tmp(mat[0].size(), mat.size() + mat[0].size());
        vector<vector<int>> ans(mat.size(), tmp);
        // if (mat[0][0] != 0)
        //     ans[0][0] = bfs(mat);

        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                if (mat[i][j] == 0)
                    ans[i][j] = 0;
                else if (mat[i][j] != 0 && (i != 0 || j != 0))
                {
                    if (i == 0)
                        ans[i][j] = ans[i][j - 1] + 1;
                    else if (j == 0)
                        ans[i][j] = ans[i - 1][j] + 1;
                    else
                        ans[i][j] = min({ans[i-1][j], ans[i][j-1]}) + 1;
                }
            }
        }
        for (int i = mat.size() - 1; i >= 0; --i)
        {
            for (int j = mat[0].size() - 1; j >= 0; --j)
            {
                if (mat[i][j] == 0)
                    ans[i][j] = 0;
                else if (mat[i][j] != 0 && (i != mat.size() - 1 || j != mat[0].size() - 1))
                {
                    if (i == mat.size() - 1)
                        ans[i][j] = min({ ans[i][j], ans[i][j + 1] + 1 });
                    else if (j == mat[0].size() - 1)
                        ans[i][j] = min({ ans[i][j], ans[i + 1][j] + 1 });
                    else
                        ans[i][j] = min({ ans[i][j], min({ ans[i + 1][j], ans[i][j + 1] }) + 1 });
                }
            }
        }
        return ans;
    }
};
// @lc code=end

