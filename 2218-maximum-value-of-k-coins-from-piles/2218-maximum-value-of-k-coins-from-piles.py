class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        n = len(piles)
        dp = [[-1]*(k+1) for _ in range(n)]

        def dfs(i, coins):
            if i == n:
                return 0
            
            if dp[i][coins] != -1:
                return dp[i][coins]
            
            res = dfs(i+1, coins)
            curr_piles = 0
            for j in range(min(coins, len(piles[i]))):
                curr_piles += piles[i][j]
                res = max(res, curr_piles+dfs(i+1, coins-j-1))

            dp[i][coins] = res

            return res
        
        return dfs(0, k)