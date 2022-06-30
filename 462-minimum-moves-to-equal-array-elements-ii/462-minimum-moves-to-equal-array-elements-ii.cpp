class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        long long int fcs[nums.size()];
        long long int total = 0;

        long long int prev = 0;

        for (int i = 0; i < nums.size(); i++) {
            fcs[i] = nums[i]+prev;
            prev = fcs[i];
            total += nums[i];
        }

        long long int ans = LONG_LONG_MAX;

        for (long long int i = 0; i < nums.size(); i++) {
            long long int num = nums[i];
            long long int prev_sum = 0;
            if (i-1 >= 0) prev_sum = fcs[i-1];
            long long int next_sum = total-fcs[i];
            long long int n = nums.size();
            long long int ansHere = next_sum-num*(n-i-1);
            long long int ii = i;
            long long int temp = (long long int)(ii*num);
            ansHere += temp-prev_sum;

            ans = min(ans, ansHere);
        }

        return (int) ans;
    }
};