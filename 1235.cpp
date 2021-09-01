// Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
    int dp[100005];

    int n;

    struct job {
        int startTime;
        int endTime;
        int profit;
    } jobs[100005];

    static bool compare(job aa, job bb) {
        return aa.startTime < bb.startTime;
    }

    int findNext(int pos) {
        int lo = pos;
        int hi = n-1;

        int ret = n;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if (jobs[mid].startTime >= jobs[pos].endTime) {
                ret = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        return ret;
    }

    int go(int position) {
        if (position >= n) return 0;
        if (dp[position] != -1) return dp[position];

        int ret1 = jobs[position].profit+go(findNext(position));
        int ret2 = go(position+1);

        return dp[position] = max(ret1, ret2);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        for (int i = 0; i < startTime.size(); i++) {
            jobs[i].startTime = startTime[i];
            jobs[i].endTime = endTime[i];
            jobs[i].profit = profit[i];
        }

        sort(jobs, jobs+n, compare);

        memset(dp, -1, sizeof(dp));

        return go(0);
    }
};