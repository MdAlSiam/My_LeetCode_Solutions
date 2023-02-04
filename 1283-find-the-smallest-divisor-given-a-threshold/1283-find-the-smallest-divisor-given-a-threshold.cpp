class Solution {
    bool isPossible(vector<int>& nums, int threshold, int mid) {
        int made = 0;
        for (int num : nums) {
            made += (num+mid-1)/mid;
        }
        
        return made <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = 0;
        for (int num : nums) hi = max(num, hi);
        
        while (lo <= hi) {
            int mid = lo+(hi-lo)/2;
            
            if (isPossible(nums, threshold, mid)) {
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        
        return lo;
    } 
};