class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 10**9+7
        def add(a, b):
            return (a%MOD+b%MOD)%MOD
        
        n = len(s)
        dp = [-1 for _ in range(n)]

        def go(index):
            if index >= n:
                return 1
            
            if dp[index] != -1:
                return dp[index]
            
            ret = 0
            
            curr_num = 0
            for i in range(index, n):
                curr_num *= 10
                curr_num += ord(s[i])-ord('0')
                if curr_num <= k and curr_num >= 1:
                    ret = add(ret, go(i+1))
                else:
                    break

            dp[index] = ret
            return ret

        return go(0)