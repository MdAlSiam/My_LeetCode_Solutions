class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = -1;
        for (int num : nums) {
            if (num != prev+1) {
                return prev+1;
            }
            prev = num;
        }
        return nums.size();
    }
};