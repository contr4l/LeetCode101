/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector< int >& flowerbed, int n) {
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        int i       = 1;
        int max_cnt = 0;
        int size    = flowerbed.size();

        for (; (i < size - 1) && (max_cnt < n); i++) {
            if (flowerbed[i] == 1) {
                continue;
            }
            if ((flowerbed[i + 1] + flowerbed[i - 1] + flowerbed[i]) == 0) {
                max_cnt++;
                flowerbed[i] = 1;
            }
        }
        return max_cnt >= n;
    }
};
// @lc code=end
