public class Solution {
    int[] houses = new int[] {};
    int[][] cost = new int[][] {};
    int m; // nHomes
    int n; // nColors
    int target;

    int ans = 1_000_000_000;

    int[,,] dp = new int[,,] {};

    int go(int homeIndex, int colorIndex, int segmentSoFar) {
        if (homeIndex >= m) {
            if (segmentSoFar == target) return 0;
            return 1_000_000_000;
        }

        if (segmentSoFar > target) {
            return 1_000_000_000;
        }

        if (dp[homeIndex, colorIndex, segmentSoFar] != -1) {
            return dp[homeIndex, colorIndex, segmentSoFar];
        }

        int ret = 1_000_000_000;

        if (houses[homeIndex] == 0) {
            for (int i = 0; i < n; i++) {
                if (i+1 != colorIndex) {
                    ret = Math.Min(ret, cost[homeIndex][i] + go(homeIndex+1, i+1, segmentSoFar+1));
                }
                else {
                    ret = Math.Min(ret, cost[homeIndex][i] + go(homeIndex+1, i+1, segmentSoFar));
                }
            }
        }
        else {
            if (houses[homeIndex] != colorIndex) {
                ret = Math.Min(ret, go(homeIndex+1, houses[homeIndex], segmentSoFar+1));
            }
            else {
                ret = Math.Min(ret, go(homeIndex+1, houses[homeIndex], segmentSoFar));
            }
        }

        return dp[homeIndex, colorIndex, segmentSoFar] = ret;
    }

    public int MinCost(int[] _houses, int[][] _cost, int _m, int _n, int _target) {
        houses = _houses;
        cost = _cost;
        m = _m;
        n = _n;
        target = _target;

        dp = new int[m,n+1,target+1];

        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n+1; j++) 
                for (int k = 0; k < target+1; k++)
                    dp[i,j,k] = -1;

        // int homeIndex, int colorIndex, int segmentSoFar
        ans = go(0, 0, 0);
        
        if (ans == 1_000_000_000) return -1;

        return ans;
    }
}
