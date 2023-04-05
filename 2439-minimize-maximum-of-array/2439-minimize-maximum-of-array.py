class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        ans = 0
        sum = 0
        for i, num in enumerate(nums):
            sum += num

            ans = max(ans, int((sum+i)//(i+1)))

        return ans