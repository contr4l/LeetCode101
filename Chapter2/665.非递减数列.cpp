/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#ifndef LC_TEST
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#else
#include "utils.h"
#endif
// @lc code=start
class Solution {
public:
    bool checkPossibility(vector< int >& nums) {
        vector< int > bad;
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i] > nums[i + 1]) {
                bad.push_back(i + 1);
                if (bad.size() == 2) {
                    return false;
                }
            }
            i++;
        }
        if (bad.size() == 0) {
            return true;
        }

        int k = bad[0];
        if (k == nums.size() - 1) {
            return true;
        }
        else {
            if (nums[k + 1] >= nums[k - 1]) {
                return true;
            }
            else if (k >= 2 && nums[k - 2] <= nums[k]) {
                return true;
            }
            else if (k == 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
