class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int freq[100005];
        for (int i = 0; i < 100005; i++) {
            freq[i] = 0;
        }

        for (int num : nums) freq[num]++;

        vector<int> ans;

        for (int i = 0; i < 100005; i++) {
            if (freq[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};