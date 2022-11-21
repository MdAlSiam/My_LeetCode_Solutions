class Solution {
    int inf = 10000;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int roSize;
    int colSize;

    bool isSide(int r, int c) {
        return (r == 0 or r == roSize-1) or (c == 0 or c == colSize-1);
    }

    bool isValid(int r, int c) {
        return r >= 0 and r < roSize and c >= 0 and c < colSize;
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        roSize = maze.size();
        colSize = maze[0].size();

        vector<vector<int>> levels(roSize, vector<int>(colSize, inf));
        
        queue<pair<int, int>> q;
        levels[entrance[0]][entrance[1]] = 0;
        q.push({entrance[0], entrance[1]});

        int ans = inf;

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();

            if (levels[top.first][top.second] != 0 and (isSide(top.first, top.second))) {
                ans = min(ans, levels[top.first][top.second]);
            }

            for (int i = 0; i < 4; i++) {
                int newX = top.first + dx[i];
                int newY = top.second + dy[i];

                if (isValid(newX, newY) and levels[newX][newY] > levels[top.first][top.second]+1 and maze[newX][newY] == '.') {
                    levels[newX][newY] = levels[top.first][top.second]+1;
                    q.push({newX, newY});
                } 
            }
        }

        if (ans == inf) return -1;
        return ans;
    }
};