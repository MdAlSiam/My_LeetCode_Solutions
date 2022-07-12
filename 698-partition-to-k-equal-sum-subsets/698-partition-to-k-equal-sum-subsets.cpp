class Solution {
    bool go(vector<int>& nums, int k, int target, vector<int>& sums, int index) {
        if (index == nums.size()) {
            // for (int sum : sums) if (sum != target) return false;
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (sums[i]+nums[index] > target) continue;
            if (i > 0 and sums[i] == sums[i-1]) continue;
            
            sums[i] += nums[index];
            if (go(nums, k, target, sums, index+1)) return true;
            sums[i] -= nums[index]; 
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int num : nums) total += num;

        if (total%k) return false;

        sort(nums.rbegin(), nums.rend());

        vector<int> sums(k, 0);

        return go(nums, k, total/k, sums, 0);
    }
};