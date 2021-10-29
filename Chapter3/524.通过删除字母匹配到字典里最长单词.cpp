/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */
#include <string.h>
#ifndef LC_TEST
#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
#else
#include "utils.h"
#endif
// @lc code=start
bool char_cmp(string& a, string& b) {
    if (a.length() > b.length()) {
        return true;
    }
    else if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] < b[i]) {
                return true;
            }
            else if (a[i] > b[i]) {
                return false;
            }
        }
    }
    return false;
}
class Solution {
public:
    string findLongestWord(string s, vector< string >& dictionary) {
        sort(dictionary.begin(), dictionary.end(), char_cmp);
        for (auto s : dictionary) {
            cout << s << endl;
        }
        for (int i = 0; i < dictionary.size(); i++) {
            int l = 0, r = 0;
            string target = dictionary[i];
            while (l < s.length()) {
                if (s[l] == target[r]) {
                    l++;
                    r++;
                    if (r == target.length())
                        return target;
                }
                else {
                    l++;
                }
            }
        }
        return "";
    }
};
// @lc code=end
