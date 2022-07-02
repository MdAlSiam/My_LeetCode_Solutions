class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        sum = []

        s = 0

        for i in range(len(nums)):
            s += nums[i]
            sum.append(s)

        return sum