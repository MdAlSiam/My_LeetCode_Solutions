// [041] Binary Search on Answer Range
// LeetCode 410. Split Array Largest Sum

class Solution {
    int isPossible(vector<int>& nums, int mid) {
        // Kounts how many subarrays are possible in nums with sum less than or equal mid

        int kount = 0;
        int tempsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (tempsum+nums[i] <= mid) {
                tempsum += nums[i];
            }
            else {
                kount++;
                tempsum = nums[i];
            }
        }
        kount++; // The last subsequnece

        return kount;
    }
public:
    int splitArray(vector<int>& nums, int m) {

        int lo = 0;
        int hi = 0;

        for (int i = 0; i < nums.size(); i++) {
            lo = max(lo, nums[i]);
            hi += nums[i];
        }

        int mid = 0;
        int ans = 0;

        while (lo <= hi) {
            mid = (lo+hi)/2;
            cout << lo << " - " << hi << " - " << mid << endl;

            int kountOfSegment = isPossible(nums, mid);

            if (kountOfSegment <= m) {
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        return ans;
    }
};
