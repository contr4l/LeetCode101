# -*- coding: utf-8 -*-
# @Author: contr4l
# @Email: china_go.tj@163.com
# @Date:   2019-10-23 00:44:23
# @Last Modified by:   contr4l
# @Last Modified time: 2019-10-23 01:02:26

'''
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
'''

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return len(nums)

        tmp = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                tmp += 1
            nums[tmp] = nums[i]
    return tmp + 1
