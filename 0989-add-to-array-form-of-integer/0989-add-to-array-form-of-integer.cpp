class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int curr = k;
        for (int i = num.size()-1; i >= 0; i--) {
            curr += num[i];
            ans.push_back(curr%10);
            curr /= 10;
        }
        while (curr != 0) {
            ans.push_back(curr%10);
            curr /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};