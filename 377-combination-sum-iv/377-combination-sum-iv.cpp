class Solution {
    int* dp;

    int go(vector<int>& nums, int target, int sum) {
        if (sum == target) return 1;
        if (sum > target) return 0;

        if (dp[sum] != -1) return dp[sum];

        int ret = 0;

        for (int num : nums) {
            // cout << "> " << num << "->" << num+sum << endl;
            ret += go(nums, target, sum+num);
        }

        return dp[sum] = ret;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp = new int[target+1];
        // memset(dp, -1, sizeof(dp));
        for (int i = 0; i < target+1; i++) dp[i] = -1;
        return go(nums, target, 0);
    }
};