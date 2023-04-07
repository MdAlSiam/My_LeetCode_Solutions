class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])

        visited = set()

        def dfs(r, c):
            if r < 0 or c < 0 or r == ROWS or c == COLS or grid[r][c] == 0 or (r, c) in visited:
                return 0
            
            visited.add((r, c))

            return 1 + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1)
        
        land = 0
        borderLand = 0

        for i in range(ROWS):
            for j in range(COLS):
                if (grid[i][j]):
                    land += 1
                    if (i, j) not in visited and (i in [0, ROWS-1] or j in [0, COLS-1]):
                        borderLand += dfs(i, j)

        return land - borderLand