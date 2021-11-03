/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include <utility>
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
bool cmp_by_cnt(const pair< char, int >& a, const pair< char, int >& b) {
    return a.second > b.second;
}

class Solution {
public:
    
    string frequencySort(string s) {
        string res;
        map<char, int> cnt;
        for (auto i : s) {
            cnt[i]++;
        }
        int i = 0;
        vector< pair< char, int > > vec(cnt.begin(), cnt.end());
        sort(vec.begin(), vec.end(), cmp_by_cnt);
        for (auto c : vec) {
            while(c.second)
            {
                res.push_back(c.first);
                c.second--;
            }
        }
        return res;
    }
};
// @lc code=end

