class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> evens;
        vector<int> odds;

        for (int num : nums) {
            if (num%2 == 0) evens.push_back(num);
            else odds.push_back(num);
        }

        vector<int> ans;
        for (int i = 0; i < evens.size(); i++) {
            ans.push_back(evens[i]);
            ans.push_back(odds[i]);
        }

        return ans;
    }
};