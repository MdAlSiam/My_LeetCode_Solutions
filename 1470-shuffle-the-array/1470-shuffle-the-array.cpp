class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            // in left, first half number; in right, second half number
            nums[i] <<= 10;
            nums[i] |= nums[i+n];
        }

        int placingIndex = n+n-1;
        for (int i = n-1; i >= 0; i--) {
            int y = nums[i] & ((1 << 10) - 1); // removes the bits for the first half number 
            int x = nums[i] >> 10;
            nums[placingIndex--] = y;
            nums[placingIndex--] = x;
        }

        return nums;
    } 
};