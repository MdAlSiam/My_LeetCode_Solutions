// LeetCode 164: Maximum Gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
       if (nums.size() == 2) {
           return abs(nums[0]-nums[1]);
       }

       int minBucket[nums.size()] ;
       int maxBucket[nums.size()];
       for (int i = 0; i < nums.size(); i++) minBucket[i] = INT_MAX;
       for (int i = 0; i < nums.size(); i++) maxBucket[i] = INT_MIN;

       int mini = INT_MAX;
       int maxi = INT_MIN;

       for (int i = 0; i < nums.size(); i++) {
           if (nums[i] < mini) mini = nums[i];
           if (nums[i] > maxi) maxi = nums[i];
       }

       if (mini == maxi) return 0;

       int bucketSize = ((maxi-mini+nums.size())/(nums.size()-1));

       for (int i = 0; i < nums.size(); i++) {
           int bucketIndex = (nums[i]-mini)/bucketSize;
           if (nums[i] < minBucket[bucketIndex]) minBucket[bucketIndex] = nums[i];
           if (nums[i] > maxBucket[bucketIndex]) maxBucket[bucketIndex] = nums[i];
       }

       int ans = INT_MIN;
       int prev = INT_MIN;

       for (int i = 0; i < nums.size(); i++) {
           if (minBucket[i] == INT_MAX) {
               continue;
           }
           if (prev == INT_MIN) {
               prev = maxBucket[i];
               continue;
           }
           
           ans = max(ans, minBucket[i]-prev);
           prev = maxBucket[i];
       }

       return ans;
    }
};
