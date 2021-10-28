/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include <xtgmath.h>
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#else
#include "utils.h"
#endif
// @lc code=start
class Solution {
public:
    bool twosum(vector< unsigned int >& p, unsigned int target) {
        unsigned int l = 0, r = p.size() - 1;
        unsigned int tmp = 0;
        while (l <= r) {
            tmp = p[l] + p[r];
            if (tmp == target)
                return true;
            else if (tmp > target)
                r--;
            else
                l++;
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        unsigned int r = sqrt(c) + 1;
        unsigned int l = 0;
        vector<unsigned int> square;
        while (l < r) {
            square.push_back(l*l);
            l++;
        }
        return twosum(square, c);
    }
};
// @lc code=end

