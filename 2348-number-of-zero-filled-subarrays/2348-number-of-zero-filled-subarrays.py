class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = 0
        kount = 0;
        
        for num in nums:
            if num == 0:
                kount += 1
            else:
                ans += (kount*(kount+1))/2
                kount = 0
        if kount:
            ans += (kount*(kount+1))/2
        
        return int(ans)