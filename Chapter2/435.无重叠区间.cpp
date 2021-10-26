/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#ifdef LC_TEST
#include "utils.h"
#else
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
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
    int eraseOverlapIntervals(vector< vector< int > >& intervals) {

        sort(intervals.begin(), intervals.end(), start_cmp);
#ifdef LC_TEST
        print_vec_vec(intervals);
#endif
        int i = 0, cnt = 0;
        int j = 1;
        while (i + j < intervals.size()) {
            if (intervals[i][1] > intervals[i + j][0]) {
                if (intervals[i][1] > intervals[i + j][1]) {
                    // cout << "remove: " << intervals[i][0] << " " << intervals[i][1] << endl;
                    i = i + j;
                    j = 1;
                }
                else {
                    // cout << "remove: " << intervals[i + j][0] << " " << intervals[i + j][1] << endl;
                    j++;
                }
                cnt++;
            }
            else {
                i += j;
                j = 1;
            }
        }
        // cout << cnt << endl;
        return cnt;
    }
};

#ifdef LC_TEST
int main() {
    Solution                A;
    vector< vector< int > > g{{-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}};
    A.eraseOverlapIntervals(g);
    return 0;
}
#endif
// @lc code=end
