class Solution {
    vector<vector<int>> dp;

    void init_dp(int m, int n) {
        for (int i = 0; i < m; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
    }

    int go(int x, int y, int m, int n) {
        if (x == m-1 and y == n-1) return 1;
        if (x > m-1 or y > n-1) return 0;

        if (dp[x][y] != -1) return dp[x][y];

        int ret = 0;
        ret += go(x+1, y, m, n);
        ret += go(x, y+1, m, n);

        return dp[x][y] = ret;
    }
public:
    int uniquePaths(int m, int n) {
        init_dp(m, n);
        return go(0, 0, m, n);
    }
};