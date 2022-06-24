class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int kountIn[1001];
        for (int i = 0; i < 1001; i++) kountIn[i] = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                kountIn[nums[i][j]]++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < 1001; i++) {
            if (kountIn[i] == nums.size()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};