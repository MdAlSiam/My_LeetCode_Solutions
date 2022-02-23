class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int leftmost = -1, rightmost = -1;

        int ans = 0;

        for (vector<int> interval : intervals) {
            if (interval[0] > leftmost and interval[1] > rightmost) {
                ans++;
                leftmost = interval[0];
            }

             rightmost = max(rightmost, interval[1]);
        }

        return ans;
    }
};