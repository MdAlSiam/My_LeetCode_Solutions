class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int timesPresentInA[1100];
        int timesPresentInB[1100];
        for (int i = 0; i < 1100; i++) {
            timesPresentInA[i] = timesPresentInB[i] = 0;
        }

        for (int num : nums1) {
            timesPresentInA[num]++;
        }

        for (int num : nums2) {
            timesPresentInB[num]++;
        }

        vector<int> ans;

        for (int i = 0; i < 1001; i++) {
            int toKeep = min(timesPresentInA[i], timesPresentInB[i]);
            while (toKeep--) ans.push_back(i);
        }

        return ans;
    }
};