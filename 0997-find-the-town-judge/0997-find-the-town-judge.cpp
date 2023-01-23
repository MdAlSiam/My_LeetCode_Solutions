class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int isTruested[n];
        int trusts[n];

        for (int i = 0; i < n; i++) {
            isTruested[i] = 0;
            trusts[i] = 0;
        }

        for (vector<int> aTrust : trust) {
            trusts[aTrust[0]-1]++;
            isTruested[aTrust[1]-1]++;
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (trusts[i] == 0 and isTruested[i] == n-1) {
                ans = i+1;
                break;
            }
        }

        return ans;
    }
};