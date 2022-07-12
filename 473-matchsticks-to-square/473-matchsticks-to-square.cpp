class Solution {
    bool go(vector<int>& matchsticks, vector<int>& sums, int target, int index) {
        if (index >= matchsticks.size()) {
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sums[i]+matchsticks[index] > target) continue;

            sums[i] += matchsticks[index];
            if (go(matchsticks, sums, target, index+1)) return true;
            sums[i] -= matchsticks[index];
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        for (int stick : matchsticks) total += stick;

        if (total%4) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sums(4);

        return go(matchsticks, sums, total/4, 0);
    }
};