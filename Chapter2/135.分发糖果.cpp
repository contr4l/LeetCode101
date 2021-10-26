/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#ifdef LC_TEST
#include "utils.h"
#else
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
#endif

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> cnt(size, 1);
        for (size_t i = 0; i < size-1; i++)
        {
            if (ratings[i] < ratings[i+1] && cnt[i] >= cnt[i+1])
            {
                cnt[i+1] = cnt[i] + 1;
            }
        }
        for (size_t i = size-1; i > 0; i--)
        {
            if (ratings[i-1] > ratings[i] && cnt[i-1] <= cnt[i])
            {
                cnt[i-1] = cnt[i] + 1;
            }
        }
        #ifdef LC_TEST
        print_vector(ratings);
        print_vector(cnt);
        #endif
        return accumulate(cnt.begin(), cnt.end(), 0);
        
    }
};

#ifdef LC_TEST
int main()
{
    Solution A;
    vector <int> b {1,3,2,2,1};
    A.candy(b);
    return 0;
}
#endif
// @lc code=end

