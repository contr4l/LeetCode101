"""
Topic: 旋转数组
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
"""
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        cnt = 0
        k %= n
        start = 0
        while cnt < n: 
            idx = start
            prev = nums[idx]
            flag = 1
            while idx != start or flag:
                flag = 0
                nxt = (idx + k) % n
                nums[nxt], prev = prev, nums[nxt]
                idx = nxt
                cnt += 1
            start += 1

