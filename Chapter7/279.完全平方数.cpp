/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
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
    int numSquares(int n) {
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                dp[i] = min(dp[i], dp[i - k * k] + 1);
            }
        }
        // print_vector(dp);
        return dp[n];
    }
};
// @lc code=end

int main()
{
    Solution A;
    A.numSquares(12);
    return 0;
}

