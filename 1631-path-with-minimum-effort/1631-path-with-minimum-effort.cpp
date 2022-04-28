class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int costs[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                costs[i][j] = INT_MAX;
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        costs[0][0] = 0;

        int deltas[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            int costTillHere = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n-1 and y == m-1) {
                return costTillHere;
            }

            for (int i = 0; i < 4; i++) {
                int xx = x+deltas[i][0];
                int yy = y+deltas[i][1];

                if (xx >= 0 and xx < n and yy >= 0 and yy < m) {
                    int newCost = max(costTillHere, abs(heights[x][y]-heights[xx][yy]));

                    if (newCost < costs[xx][yy]) {
                        costs[xx][yy] = newCost;
                        pq.push({newCost, {xx, yy}});
                    }
                }
            }
        }

        return costs[n-1][m-1];
    }
};