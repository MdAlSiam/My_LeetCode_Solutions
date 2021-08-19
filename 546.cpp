// LeetCode 546: Remove Boxes

class Solution {
    int dp[110][110][110];
    void init_dp() {
        for (int i = 0; i < 110; i++) {
            for (int j = 0; j < 110; j++) {
                for (int k = 0; k < 110; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
    }

    int go(vector<int>& boxes, int start, int stop, int curr_streak) {
        if (start > stop) return 0;
        if (start == stop) return (curr_streak+1)*(curr_streak+1);
        
        if (dp[start][stop][curr_streak] != -1) return dp[start][stop][curr_streak];

        int ret = 0;

        ret = max(ret, (curr_streak+1)*(curr_streak+1)+go(boxes, start+1, stop, 0));

        for (int i = start+1; i <= stop; i++) {
            if (boxes[start] == boxes[i]) {
                ret = max(ret, go(boxes, start+1, i-1, 0)+go(boxes, i, stop, curr_streak+1));
            }
        }

        return dp[start][stop][curr_streak] = ret;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        init_dp();
        int ans = go(boxes, 0, boxes.size()-1, 0);
        return ans;
    }
};