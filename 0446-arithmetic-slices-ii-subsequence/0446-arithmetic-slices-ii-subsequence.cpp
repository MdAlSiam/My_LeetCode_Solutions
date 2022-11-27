class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<map<int, int> > dp(nums.size());

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long long int diff = (long long int)nums[i]-(long long int)nums[j];
                if (diff < INT_MIN or diff > INT_MAX) continue;

                dp[i][diff]++;
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
            }
        }

        return ans;
    }
};