class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int> flattenedBoard(n*n);

        bool reversed = false;

        int index = 0;

        for (int ro = n-1; ro >= 0; ro--) {
            if (reversed) {
                for (int col = n-1; col >= 0; col--) {
                    flattenedBoard[index++] = board[ro][col];
                }
            }
            else {
                for (int col = 0; col < n; col++) {
                    flattenedBoard[index++] = board[ro][col];
                }
            }
            reversed = !reversed;
        }

        queue<int> q;

        vector<int> levels(n*n, -1);
        levels[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            if (curr == n*n - 1) return levels[curr];
            q.pop();

            for (int i = curr+1; i <= curr+6; i++) {
                if (i >= n*n) break;

                if (flattenedBoard[i] == -1) {
                    if (levels[i] == -1) {
                        levels[i] = levels[curr]+1;
                        q.push(i);
                    }
                }
                else {
                    if (levels[flattenedBoard[i]-1] == -1) {
                        levels[flattenedBoard[i]-1] = levels[curr]+1;
                        q.push(flattenedBoard[i]-1);
                    }
                }
            }
        }

        return -1;
    }
};