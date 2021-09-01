class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int maxLen = m;
        int maxWidth = n;
        for (int i = 0; i < ops.size(); i++) {
            maxLen = min(ops[i][0], maxLen);
            maxWidth = min(ops[i][1], maxWidth);
        }
        
        return maxLen*maxWidth;
    }
};