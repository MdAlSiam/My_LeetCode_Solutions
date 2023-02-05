class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int ro = 0;
        int col = 0;

        while (ro < n and col < n) {
            int currRo = ro;
            int currCol = col;

            while (currRo < n and currCol < n) {
                swap(matrix[ro][currCol], matrix[currRo][col]);
                currRo++;
                currCol++;
            }

            ro++;
            col++;
        }

        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};