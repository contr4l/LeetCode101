/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#ifndef LC_TEST
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#else
#include "utils.hpp"
#endif

/*
假设两个有序数组分别是A和B。要找到第k个元素，我们可以比较A[k/2−1]和B[k/2−1]，
其中/表示整数除法。由于A[k/2−1]和B[k/2−1]的前面分别有A[0..k/2−2]
和B[0..k/2−2]，即k/2−1个元素，对于A[k/2−1]和B[k/2−1]中的较小值，
最多只会有(k/2−1)+(k/2−1)≤k−2(k/2−1)+(k/2−1)≤k−2个元素比它小，那么它就不能是
第k小的数了。
 */
// @lc code=start
#define MAX(A, B) (A >= B ? A : B)
class Solution {
public:
    double findMedianSortedArrays(vector< int >& nums1, vector< int >& nums2) {
        int iA = 0, iB = 0;
        int total = (nums1.size() + nums2.size());
        int mid_1, mid_2;
        if (total % 2) {
            mid_1 = mid_2 = total / 2;
        }
        else {
            mid_2 = total / 2;
            mid_1 = mid_2 - 1;
        }
        while (iA + iB < mid_1) {
            if (iA < nums1.size() && iB < nums2.size()) {
                if (nums1[iA] <= nums2[iB]) {
                    iA++;
                }
                else {
                    iB++;
                }
            }
            else if (iA == nums1.size()) {
                iB++;
            }
            else {
                iA++;
            }
        }
        cout << iA << " " << iB;
        if (iA == nums1.size()) {
            return total % 2 ? nums2[iB] : (nums2[iB] + nums2[iB + 1]) / 2.0;
        }
        else if (iB == nums2.size()) {
            return total % 2 ? nums1[iA] : (nums1[iA] + nums1[iA + 1]) / 2.0;
        }
        else {
            if (total % 2) {
                return min(nums1[iA], nums2[iB]);
            }
            else {
                if (nums1[iA] < nums2[iB] && iA < nums1.size() - 1) {
                    return (nums1[iA] + min(nums1[iA + 1], nums2[iB])) / 2.0;
                }
                else if (nums1[iA] > nums2[iB] && iB < nums2.size() - 1) {
                    return (nums2[iB] + min(nums1[iA], nums2[iB + 1])) / 2.0;
                }
                return (nums1[iA] + nums2[iB]) / 2.0;
            }
        }
        return 0;
    }
};
// @lc code=end
