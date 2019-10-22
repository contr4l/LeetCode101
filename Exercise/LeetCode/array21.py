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
