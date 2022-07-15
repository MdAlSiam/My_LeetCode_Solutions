public class Solution {
    int[] dx = new int[] {-1, 1, 0, 0};
    int[] dy = new int[] {0, 0, -1, 1};
    
    bool isValid(ref int[][] grid, int r, int c) {
        if (r >= 0  && r < grid.Length && c >= 0  && c < grid[0].Length && grid[r][c] == 1) {
            return true;
        }
        return false;
    }
    
    int dfs(ref int[][] grid, int r, int c) {
        int ret = 1;
        
        grid[r][c] = 2;
        
        for (int i = 0; i < 4; i++) {
            int newR = r+dx[i];
            int newC = c+dy[i];

            if(isValid(ref grid, newR, newC)) {
                ret += dfs(ref grid, newR, newC);
            }
        }
        
        return ret;
    }
    
    public int MaxAreaOfIsland(int[][] grid) {
        int ans = 0;
        for (int i = 0; i < grid.Length; i++) {
            for (int j = 0; j < grid[0].Length; j++) {
                if (grid[i][j] == 1) {
                    ans = Math.Max(ans, dfs(ref grid, i, j));
                }
            }
        }

        return ans;
    }
}