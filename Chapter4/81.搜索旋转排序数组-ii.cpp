/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
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
    int my_binary_search(vector< int > nums, int target, int l, int r) {
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target){
                return true;
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0, r = size - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] == nums[l]) {
                l++;
            }
            else if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return false;
        // if (start == size - 1) {
        //     // sorted
        //     return my_binary_search(nums, target, 0, size - 1);
        // }
        // // cout << "twist position: " << start + 1 << ", value = " << nums[start + 1];
        // // cout << start+1 << " [search area] " << start + size << endl;
        // return my_binary_search(nums, target, start + 1, size - 1) || my_binary_search(nums, target, 0, start);
    }
};
// @lc code=end
#ifdef LC_TEST
int main()
{
    Solution A;
    vector<int> nums{2,3,4,5,6,7,1};
    int target = 0;
    bool ret = A.search(nums, target);
    print_vector(nums);
    cout << ret << endl;
    return 0;
}
#endif
