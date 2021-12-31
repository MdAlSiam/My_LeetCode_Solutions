// https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        int minAbsDiff = 100000000;

        for (int i = 1; i < arr.size(); i++) {
            minAbsDiff = min(minAbsDiff, arr[i]-arr[i-1]);
        }

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i]-arr[i-1] == minAbsDiff) {
                ans.push_back({arr[i-1], arr[i]});
            }
        }

        return ans;
    }
};