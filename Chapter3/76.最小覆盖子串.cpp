/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#ifndef LC_TEST
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#else
#include "utils.h"
#endif
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 'a' - 'z' : 0 ~ 25, 'A' - 'Z' 26 ~ 51
        set< char > _set;
        unordered_map< char, int > _map_t;
        unordered_map< char, int > _map_s;

        for (auto c : t) {
            _set.insert(c);
            _map_t[c]++;
        }
        for (auto c : s) {
            _map_s[c]++;
        }
        for (auto i : _set) {
            if (_map_t[i] > _map_s[i])
                return "";
        }
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            // shift right
            if (_map_t[s[r]] != 0 && (_map_s[s[r]] == _map_t[s[r]])) {
                break;
            }
            _map_s[s[r]]--;
            r--;
        }
        while (l <= r) {
            // shift right
            if (_map_t[s[l]] != 0 && (_map_s[s[l]] == _map_t[s[l]])) {
                break;
            }
            _map_s[s[l]]--;
            l++;
        }

        if (l == r){
            return s.substr(l, 1);
        }

        int pos = l;
        int len = r - l + 1;

        while (r < s.size()) {
            r++;
            _map_s[s[r]]++;
            while (r < s.size() && s[r] != s[l]) {
                r++;
                if (r < s.size())
                    _map_s[s[r]]++;
                
            }
            if (r == s.size())
                break;

            _map_s[s[l]]--;
            l++;
            // cout << l << " to " << r << endl;
            // cout << s.substr(l, r-l+1) << endl;
            
            while (l < r) {
                if (_map_t[s[l]] !=0 &&_map_s[s[l]] <= _map_t[s[l]]){
                    break;
                }
                _map_s[s[l]]--;
                l++;
            }

            if (l < r && len > r - l + 1) {
                pos = l;
                len = r - l + 1;
            }
            // cout << l << " " << r << endl;
            // cout << s.substr(l, r-l+1) << endl;

        }
        cout << pos << " " << len << endl;
        return s.substr(pos, len);
    }
};

// @lc code=end
