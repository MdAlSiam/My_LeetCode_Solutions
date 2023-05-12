class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> activepoints(questions.size()+1, 0);

        for (int i = questions.size()-1; i >= 0; i--) {
            long long nottake = activepoints[i+1];
            long long take = questions[i][0] + ((i+questions[i][1]+1) <= questions.size() ? activepoints[i+questions[i][1]+1] : 0);
            activepoints[i] = max(take, nottake);
        }

        return activepoints[0];
    }
};