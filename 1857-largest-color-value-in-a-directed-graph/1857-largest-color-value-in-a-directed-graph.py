class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        for src, dst in edges:
            adj[src].append(dst)

        def dfs(node):
            if node in path:
                return float('inf')
            if node in visited:
                return 0
            
            visited.add(node)
            path.add(node)

            colorIndex = ord(colors[node])-ord('a')
            count[node][colorIndex] = 1

            for nei in adj[node]:
                if (dfs(nei) == float('inf')):
                    return float('inf')
                
                for c in range(26):
                    count[node][c] = max(
                        count[node][c],
                        (1 if c == colorIndex else 0) + count[nei][c] 
                    )

            path.remove(node)
            return max(count[node])
        
        n = len(colors)
        res = 0
        visited = set()
        path = set()
        count = [[0]*26 for i in range(n)]

        for i in range(n):
            res = max(res, dfs(i))
        
        return -1 if res == float('inf') else res

