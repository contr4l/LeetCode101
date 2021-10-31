/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
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
    int singleNonDuplicate(vector< int >& nums) {
        int l = 0, r = nums.size() - 1;
        if (r == 0) {
            return nums[r];
        }
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 1) {
                    r = mid - 1;
                }
                else {
                    l = mid + 2;
                }
            }
            else {
                if ((mid + 2 == nums.size()) || (nums[mid + 1] != nums[mid + 2])) {
                    return nums[mid + 1];
                }

                else if (mid == 0 || nums[mid - 1] != nums[mid]) {
                    return nums[mid];
                }
                // 四连相等，判断
                else {
                    if (mid % 2) {
                        l = mid + 3;
                    }
                    else {
                        r = mid - 2;
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

