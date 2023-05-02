class Solution:
    def arraySign(self, nums: List[int]) -> int:
        nc = 0
        zc = 0
        for num in nums:
            if num < 0: nc += 1
            elif num == 0: zc += 1
                
        if zc: return 0
        elif nc%2: return -1
        else: return 1
            