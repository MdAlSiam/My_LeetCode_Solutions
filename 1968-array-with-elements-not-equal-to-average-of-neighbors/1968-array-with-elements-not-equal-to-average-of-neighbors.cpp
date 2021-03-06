class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = nums.size()-1;

        while (lo <= hi) {
            if (lo == hi) {
                ans.push_back(nums[lo]);
                break;
            }

            ans.push_back(nums[lo]);
            ans.push_back(nums[hi]);

            lo++;
            hi--;
        }

        return ans;
    }
};