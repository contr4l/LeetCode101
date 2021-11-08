/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
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
    bool search(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, string &tmp, string &word)
    {
        // printf("now: i=%d, j=%d, char=%c, tmp=%s.\n", i, j, board[i][j], tmp.c_str());
        bool res = false;
        if (tmp.length() == word.length())
        {
            return true;
        }
        visited[i][j] = 1;
        int off[] = { -1, 0, 1, 0, -1 };
        int k = 0;
        while (k < 4)
        {
            int new_i = i + off[k];
            int new_j = j + off[k + 1];
            if (new_i < 0 || new_i >= board.size() || new_j < 0 || new_j >= board[0].size() || visited[new_i][new_j])
            {
                k++;
                continue;
            }
            if (board[new_i][new_j] != word[tmp.length()])
            {
                k++;
                continue;
            }
            tmp += board[new_i][new_j];
            res |= search(board, visited, new_i, new_j, tmp, word);
            if (res){
                return true;
            }
            tmp.pop_back();
            k++;
        }
        visited[i][j] = 0;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<int> tmp(n, 0);
        vector<vector<int>> visited(m, tmp);
        string tmp_str;
        tmp_str += word[0];

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0] && search(board, visited, i, j, tmp_str, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

