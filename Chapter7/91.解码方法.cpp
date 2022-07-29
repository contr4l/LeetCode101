/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int validij(char i, char j)
    {
        if (i == '1' ||  (i == '2' && j <= '6' && j >= '0'))
            return 1;
        else
            return 0;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length()+1, 1);
        // dp[i+1]表示s[:i]能构成的表示方法数
        if (s[0] == '0')
            return 0;

        for (int i=2; i<s.length()+1; i++)
        {
            dp[i] = dp[i-2]*validij(s[i-2], s[i-1]);
            dp[i] += dp[i-1]* (s[i-1] != '0');
        }
        return dp[s.length()];
    }
};
// @lc code=end

