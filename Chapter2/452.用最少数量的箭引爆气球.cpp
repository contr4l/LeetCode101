/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
bool int_cmp(vector< int >& a, vector< int >& b) {
    if (a[0] < b[0]) {
        return true;
    }
    else if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return false;
}
class Solution {
public:
    int findMinArrowShots(vector< vector< int > >& points) {
        sort(points.begin(), points.end(), int_cmp);
        int cnt  = 0;
        int size = points.size();
        int prev = points[0][1];
        for (int i = 0; i < size - 1; i++) {
            if (points[i + 1][0] > prev) {
                cnt++;
                prev = points[i + 1][1];
            }
            else{
                prev = min(prev, points[i + 1][1]);
            }
        }
        return ++cnt;
    }
};
// @lc code=end

