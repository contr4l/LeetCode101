/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#ifndef LC_TEST
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
#else
#include "utils.h"
#endif

// @lc code=start
bool start_cmp(vector< int >& a, vector< int >& b) {
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
    vector<int> partitionLabels(string s) {
        int start[26] = {0};
        fill_n(start, 26, -1);
        int end[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (start[s[i] - 'a'] == -1) {
                start[s[i] - 'a'] = i;
                end[s[i] - 'a']   = i;
            }
            else {
                end[s[i] - 'a'] = i;
            }
        }
        vector<vector<int>> s_e;
        for (int i = 0; i < 26; i++)
        {
            if (start[i]!=-1){
                // printf("%c:%d %d.\n", 'a'+i, start[i], end[i]);
                s_e.push_back({start[i], end[i]});
            }
        }
        sort(s_e.begin(), s_e.end(), start_cmp);
        vector<int> res;
        int start_ = s_e[0][0];
        int end_ = s_e[0][1];
        for (int i = 1; i < s_e.size(); i++)
        {
            if (s_e[i][0] < end_){
                end_ = max(end_, s_e[i][1]);
            }
            else {
                res.push_back(end_ - start_ +1);
                start_ = s_e[i][0];
                end_ = s_e[i][1];
            }
        }

        res.push_back(end_ - start_ +1);
        #ifdef LC_TEST
        print_vector(res);
        #endif
        return res;
    }
};

// @lc code=end
#ifdef LC_TEST
int main()
{
    char* S = "ababcbacadefegdehijhklij";
    Solution A;
    // print_vec_vec(g);
    A.partitionLabels(S);
    return 0;
}
#endif
