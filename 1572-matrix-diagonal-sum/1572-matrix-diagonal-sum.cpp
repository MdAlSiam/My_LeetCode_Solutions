class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;

        int r = 0;
        int c = 0;

        while (r < mat.size() and c < mat.size()) {
            ans += mat[r][c];

            r++;
            c++;
        }

        r = 0;
        c = mat.size()-1;

        while (r < mat.size() and c >= 0) {
            if (r != c) ans += mat[r][c];
            r++;
            c--;
        }

        return ans;
    }
};