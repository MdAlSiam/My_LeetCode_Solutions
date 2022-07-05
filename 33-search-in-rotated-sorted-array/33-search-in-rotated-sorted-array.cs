public class Solution {
    public int Search(int[] nums, int target) {
        int lo = 0;
        int hi = nums.Length-1;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if (nums[mid] == target)  {
                return mid;
            }

            if (nums[mid] >= nums[lo]) {
                // The left upper portion
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            else {
                // The right lower portion
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
        }

        return -1;
    }
}