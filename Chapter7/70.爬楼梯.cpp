/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int f1 = 1, f2 = 2;
        int tmp = 0;
        while (n > 2)
        {
            tmp = f2;
            f2 += f1;
            f1 = tmp;
            n--;
        }
        return f2;
    }
};
// @lc code=end

