class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int fcs[nums.size()]; // Cumulative Summation
        int total = 0; // Total summation of the array nums

        int prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            fcs[i] = nums[i]+prev;
            prev = fcs[i];
            total += nums[i];
        }

        long long int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            long long int n = nums.size();
            long long int num = nums[i];
            long int prev_sum = 0;
            if (i-1 >= 0) prev_sum = fcs[i-1];
            long long int next_sum = total-fcs[i];
            long long int ansHere = next_sum-num*(n-i-1);
            long long int ii = i;
            ansHere += ii*num-prev_sum;

            ans = min(ans, ansHere);
        }

        return (int) ans;
    }
};