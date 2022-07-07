public class Solution {
    public int FindMin(int[] nums) {
        int lo = 0;
        int hi = nums.Length-1;

        while (lo <= hi) {
            if (lo == hi) {
                return nums[lo];
            }
            
            int mid = lo + (hi-lo)/2;

            if (nums[mid] >= nums[lo] && nums[mid] <= nums[hi]) {
                // Non-mixed portion
                if (mid-1 < 0 || nums[mid-1] > nums[mid]) return nums[mid];
                else hi = mid-1;
            }
            else {
                // Mixed portion
                if (nums[mid] > nums[hi]) {
                    // Left Portion
                    lo = mid+1;
                }
                else {
                    // Right Portion
                    if (nums[mid-1] > nums[mid]) return nums[mid];
                    else hi = mid-1;
                }
            }
        }

        return -1; 
    }
}