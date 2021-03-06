class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);

        priority_queue<pair<int, int>> pq;

        /*
        // Reverse Approach

        for (int i = nums.size()-1; i >= 0; i--) {
            while (!pq.empty() && pq.top().second > i+k) pq.pop();

            dp[i] += nums[i] + (pq.size() ? pq.top().first : 0);

            pq.push({dp[i], i});
        }

        return dp[0];
        */

        for (int i = 0; i < nums.size(); i++) {
            while (!pq.empty() and pq.top().second < i-k) pq.pop();

            dp[i] += nums[i] + (pq.size() ? pq.top().first : 0);

            pq.push({dp[i], i});
        }

        return dp[nums.size()-1];
    }
};