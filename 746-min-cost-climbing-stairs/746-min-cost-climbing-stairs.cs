public class Solution {
    public int MinCostClimbingStairs(int[] cost) {
        int[] dp = new int[cost.Length+1];
        Array.Fill(dp, 0);

        for (int i = 2; i < cost.Length+1; i++) {
            dp[i] = Math.Min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }

        return dp[cost.Length];
    }
}
