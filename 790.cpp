class Solution {
    int mod = 1000000007;

    int multiply(int n1, int n2) {
        return ((n1%mod)*(n2%mod))%mod;
    }

    int add(int n1, int n2) {
        return ((n1%mod)+(n2%mod))%mod;
    }
public:
    int numTilings(int n) {
        int dp[n+10];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = add(multiply(2, dp[i-1]), dp[i-3]);
        }

        return dp[n];
    }
};