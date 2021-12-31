class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int num : nums) target += num;
        if (target & 1) return false;

        target /= 2;

        bool dp[nums.size()+1][target+1];

        for (int i = 0; i <= nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (i == 0 and j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = false;
                else if (j == 0) dp[i][j] = true;
                else {
                    dp[i][j] = dp[i-1][j]; 
                    if (j-nums[i-1] >= 0) dp[i][j] |= dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[nums.size()][target];
    }
};