/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
#ifndef LC_TEST
#include <iterator>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#else
#include "utils.hpp"
#endif
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int upper_bound = min(0x10000, x);
        int lower_bound = 0;
        while (lower_bound <= upper_bound)
        {
            int mid = (upper_bound + lower_bound) / 2;
            unsigned int tmp = (unsigned int)mid * (unsigned int)mid;
            unsigned int tmp_1 = (unsigned int)(mid+1) * (unsigned int)(mid+1);
            if (tmp <= x && tmp_1 >x){
                return mid;
            }
            else if ( tmp_1 <= x){
                lower_bound = mid+1;
            }
            else {
                upper_bound = mid-1;
            }
            // cout << lower_bound << " " << upper_bound << endl;
        }
        return 0;
    }
};
// @lc code=end
#ifdef LC_TEST
int main()
{
    Solution A;
    int ret = A.mySqrt(2147483647);
    cout << ret << endl;
    return 0;
}
#endif
