/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
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
    bool isPalindrome(string& s, int i, int j) {
        int l = i, r = j;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};
// @lc code=end
