/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        int profit = 0;
        int start = 0;
        while (start < n - 1)
        {
            if (prices[start+1] > prices[start]){
                profit += prices[start+1] - prices[start];
            }
            else {
                res += profit;
                profit = 0;
            }
            start++;
        }
        return profit + res;
    }
};
// @lc code=end

