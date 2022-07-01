class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int num : nums) {
            ans += (num-nums[0]);
            /*
            Increasing all other elements by one is equivalent to decreasing the biggest element by one.
            All the elements should be decreased to the smallest
            */
        }

        return ans;
    }
};