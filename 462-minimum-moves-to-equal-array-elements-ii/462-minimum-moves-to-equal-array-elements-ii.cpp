class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int fcs[nums.size()]; // Cumulative Summation
        int total = 0; // Total summation of the array nums

        // Calculating cumulative summation (fcs) and total summation (total)
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
            if (i-1 >= 0) prev_sum = fcs[i-1]; // prev_sum is the summation of the previous elements [index 0 to i-1]
            long long int next_sum = total-fcs[i]; // next_sum is the summation of the next elements [index i+1 to last]

            // As the array is sorted, all of the previous elements are less than or equal to num
            // and all of the next elements are greater than or equal to num

            // All of the next elements should be reduced to num
            // Let's say all of the next elements should be reduced to 0, hence total of 'next_sum' operations will be needed
            // But as the next elemetns will be num (not 0), hence num*(n-i-1) less operations will be needed

            long long int ansHere = next_sum-num*(n-i-1); 
            long long int ii = i;

            // All of the previous elements will be incereased to num
            // Let's say, all of the previous elements are 0
            // Hence ii*num operations will be needed
            // But all are not 0, so prev_sum less operations will be needed

            ansHere += ii*num-prev_sum;

            ans = min(ans, ansHere);
        }

        return (int) ans;
    }
};