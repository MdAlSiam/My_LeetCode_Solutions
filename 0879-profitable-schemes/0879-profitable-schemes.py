class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        MOD = 10**9 + 7

        DP = {}
        def dfs(i, n, p):
            if i == len(group):
                return 1 if p >= minProfit else 0
            
            if (i, n, p) in DP:
                return DP[(i, n, p)]

            DP[(i, n, p)] = dfs(i + 1, n, p)
            if n - group[i] >= 0:
                DP[(i, n, p)] += dfs(i + 1, n-group[i], min(minProfit, p + profit[i])) % MOD  

            return DP[(i, n, p)] % MOD 

        return dfs(0, n, 0)