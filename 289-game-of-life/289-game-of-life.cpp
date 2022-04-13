class Solution {
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int isValid(int pos_x, int pos_y, int nRows, int nCols) {
        return 0 <= pos_x and pos_x < nRows and 0 <= pos_y and pos_y < nCols;
    }

    int nNeighbors(vector<vector<int>>& board, int x, int y) {
        int ret = 0;

        for (int i = 0; i < 8; i++) {
            int neighborX = x+dx[i];
            int neighborY = y+dy[i];

            if (isValid(neighborX, neighborY, board.size(), board[0].size())) {
                if (board[neighborX][neighborY] == 1 or board[neighborX][neighborY] == 4) {
                    ret++;
                }
            }
        }

        return ret;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                int nAlive = nNeighbors(board, i, j);

                if (board[i][j] == 1) {
                    if (nAlive <= 1) {
                        board[i][j] = 4;
                    }
                    else if (nAlive == 2 or nAlive == 3) {
                        // board[i][j] = 5;
                    }
                    else {
                        board[i][j] = 4;
                    }
                }
                else {
                    if (nAlive == 3) {
                        board[i][j] = 6;
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 4) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 6) {
                    board[i][j] = 1;
                }
            }
        }
    }
};