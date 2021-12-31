class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            int consecutive = 0;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] >= 1) {
                    consecutive++;
                    grid[i][j] = consecutive;
                }
                else {
                    consecutive = 0;
                }
            }

            consecutive = 0;
            for (int j = grid[0].size()-1; j >= 0; j--) {
                if (grid[i][j] >= 1) {
                    consecutive++;
                    grid[i][j] = min(grid[i][j], consecutive);
                }
                else {
                    consecutive = 0;
                }
            }
        }

        int kount = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                int shift = 1;
                while (i+shift < grid.size() and grid[i+shift][j] > shift) shift++;
                shift--;

                kount += shift;

                shift = 1;
                while (i-shift >= 0 and grid[i-shift][j] > shift) shift++;
                shift--;

                kount += shift;
            }
        }

        return kount;
    }
};