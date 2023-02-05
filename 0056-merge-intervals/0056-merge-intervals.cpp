class Solution {
    static bool compare(vector<int>a, vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), compare);

        int currStart = intervals[0][0];
        int currStop = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (currStop < intervals[i][0]) {
                ans.push_back({currStart, currStop});

                currStart = intervals[i][0];
                currStop = intervals[i][1];
            }
            else if (currStop < intervals[i][1]) {
                currStop = intervals[i][1];
            }
        }
        ans.push_back({currStart, currStop});

        return ans;
    }
};