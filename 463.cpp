class Solution {
    int ans;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    if (i == 0 or (i > 0 and grid[i-1][j] == 0)) ans++;
                    if (i == grid.size()-1 or (i < grid.size() and grid[i+1][j] == 0)) ans++;
                    if (j == 0 or (j > 0 and grid[i][j-1] == 0)) ans++;
                    if (j == grid[0].size()-1 or (j < grid[0].size() and grid[i][j+1] == 0)) ans++;
                }
            }
        }
        return ans;
    }
};