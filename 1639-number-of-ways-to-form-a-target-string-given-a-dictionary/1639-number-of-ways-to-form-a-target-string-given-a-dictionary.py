class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10**9 + 7

        cnt = defaultdict(int)
        for w in words:
            for i, c in enumerate(w):
                cnt[(i, c)] += 1

        dp = {}

        def dfs(i, k):
            if i == len(target): return 1
            if k == len(words[0]): return 0
            
            if (i, k) in dp: return dp[(i, k)]

            dp[(i, k)] = dfs(i, k+1)
            dp[(i, k)] += cnt[(k, target[i])]*dfs(i+1, k+1)

            return dp[(i, k)]%MOD
        
        return dfs(0, 0)