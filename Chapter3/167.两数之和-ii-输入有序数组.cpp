/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r= numbers.size()-1;
        while (l < r)
        {
            int tmp = numbers[l] + numbers[r];
            #ifdef LC_TEST
            printf("l = %d, r = %d, tmp = %d.\n", l, r, tmp);
            #endif
            if (tmp == target){
                return vector< int >{l + 1, r + 1};
            }
            else if (tmp > target){
                r--;
            }
            else {
                l++;
            }
        }
        return vector< int >{-1, -1};
    }
};
// @lc code=end

