class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool inA[1001], inB[1001];
        for (int i = 00; i < 1001; i++) {
            inA[i] = false;
            inB[i] = false;
        }

        for (int num : nums1) {
            inA[num] = true;
        }

        for (int num : nums2) {
            inB[num] = true;
        }

        vector<int> ans;

        for (int i = 0; i < 1001; i++) {
            if (inA[i] and inB[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};