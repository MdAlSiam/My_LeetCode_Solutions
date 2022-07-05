public class Solution {
    public int LongestConsecutive(int[] nums) {
        int ans = 0;

        Dictionary<int, int> d = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) { 
            d[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.Length; i++) {
            if (!d.ContainsKey(nums[i]-1)) {
                int curr = nums[i];
                int ansHere = 0;

                while (d.ContainsKey(curr)) {
                    ansHere++;
                    curr++;
                }

                ans = Math.Max(ans, ansHere);
            }
        }

        return ans;
    }
}