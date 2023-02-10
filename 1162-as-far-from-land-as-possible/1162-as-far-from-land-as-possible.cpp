class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = currX+dx[i];
                int newY = currY+dy[i];

                if (newX >= 0 and newX < n and newY >= 0 and newY < n and grid[newX][newY] == 0) {
                    grid[newX][newY] = grid[currX][currY] + 1;
                    q.push({newX, newY});

                    ans = max(ans, grid[newX][newY]);
                }
            }
        }

        return ans-1;   
    }
};