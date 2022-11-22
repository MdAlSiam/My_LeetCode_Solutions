class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];

        for (int i = 2; i <= n; i++) dp[i] = 100000;

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 1; i*i <= n; i++) dp[i*i] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; i+j*j <= n; j++) {
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
            }
        }

        // for (int i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;

        return dp[n];
    }
};