class Solution {
    vector<vector<string>> ans;
    vector<string> grid;
    int n;

    void init_grid() {
        for (int i = 0; i < n; i++) {
            string line = "";
            for (int j = 0; j < n; j++) line += ".";
            grid.push_back(line);
        }
    }

    bool isSafe(int r, int c) {
        for (int col = c; col >= 0; col--) {
            if (grid[r][col] == 'Q') return false;
        }

        for (int ro = r, col = c; ro >= 0 and col >= 0; ro--, col--) {
            if (grid[ro][col] == 'Q') return false;
        }

        for (int ro = r, col = c; ro < n and col >= 0; ro++, col--) {
            if (grid[ro][col] == 'Q') return false;
        }

        return true;
    }

    void solve(int col) {
        if (col == n) {
            ans.push_back(grid);

            return;
        }

        for (int ro = 0; ro < n; ro++) {
            if (isSafe(ro, col)) {
                grid[ro][col] = 'Q';
                solve(col+1);
                grid[ro][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int nn) {
        n = nn;
        init_grid();
        solve(0);
        return ans;
    }
};