/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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
    void search(vector< int >& tmp, vector< int >& visited, int n, int k,
                int lvl, vector< vector< int > >& res) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        if (lvl > n) {
            return;
        }
        visited[lvl] = 1;
        tmp.push_back(lvl);
        lvl += 1;
        search(tmp, visited, n, k, lvl, res);
        tmp.pop_back();
        search(tmp, visited, n, k, lvl, res);
        lvl -= 1;
        visited[lvl] = 0;
        return;
    }
    vector< vector< int > > combine(int n, int k) {
        vector< vector< int > > res;
        vector< int > tmp;
        vector< int > visited(n + 1, 0);
        search(tmp, visited, n, k, 1, res);
        return res;
    }
};
// @lc code=end

