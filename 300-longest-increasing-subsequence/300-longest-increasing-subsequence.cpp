class Solution {
public:
    int lengthOfLIS_DP(vector<int>& nums) {
        // TC: O(n^2)
        int dp[nums.size()];

        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        // TC: O(n*log n)
        vector<int> tail;

        for (int num : nums) {
            if (tail.empty() || num > tail.back()) {
                tail.push_back(num);
            }
            else {
                tail[lower_bound(tail.begin(), tail.end(), num) - tail.begin()] = num;
            }
        }

        return (int) tail.size();
    }
};