class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            if (num & 1) {

            }
            else {
                ans.push_back(num);
            }
        }
        for (int num : nums) {
            if (num & 1) {
                ans.push_back(num);
            }
            else {
                
            }
        }
        return ans;
    }
};