/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#ifndef LC_TEST
#include <stdio.h>
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
    vector<vector<int>> status_A;
    vector<vector<int>> status_B;
    void dfs(int i, int j, vector<vector<int>>& H, vector<vector<int>>& status){
        #ifdef LC_TEST
        printf("recursal: %d %d.\n", i, j);
        #endif
        if (status[i][j] == 1) {
            return;
        }
        status[i][j] = 1;
        int k[] = {0, 1, 0, -1, 0};
        for (int p = 0; p < 4; p++) {
            int ni = i + k[p];
            int nj = j + k[p + 1];
            if (ni < 0 || nj < 0 || ni >= H.size() || nj >= H[0].size()) {
                continue;
            }
            // printf("search: %d %d.\n", ni, nj);
            if (H[ni][nj] >= H[i][j]) {
                dfs(ni, nj, H, status);
            }
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<int>tmp(heights[0].size(), 0);
        status_A.resize(heights.size(), tmp);
        status_B.resize(heights.size(), tmp);

        for (int i = 0; i < heights.size(); ++i) {
            dfs(i, 0, heights, status_A);
            dfs(i, heights[0].size() - 1, heights, status_B);
        }
        for (int i = 0; i < heights[0].size(); ++i) {
            dfs(0, i, heights, status_A);
            dfs(heights.size() - 1, i, heights, status_B);
        }

        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (status_A[i][j] == 1 && status_B[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        #ifdef LC_TEST
        print_vec_vec(status_A);
        print_vec_vec(status_B);
        print_vec_vec(res);
        #endif
        return res;
    }
};
// @lc code=end
int main()
{
    Solution A;
    vector< vector< int > > heights{{1,1},{1,1},{1,1}};
    A.pacificAtlantic(heights);
    return 0;
}
