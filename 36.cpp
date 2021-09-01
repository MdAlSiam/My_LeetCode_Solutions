class Solution {
    bool isValidPortion(vector<vector<char>>& grid, int ro_start, int ro_stop, int col_start, int col_stop) {
        map<char, int> mp;
        for (int i = ro_start; i <= ro_stop; i++) {
            for (int j = col_start; j <= col_stop; j++) {
                if (grid[i][j] == '.')  continue;
                if (mp.count(grid[i][j])) return false;
                mp[grid[i][j]] = 1;
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (not isValidPortion(board, i, i+2, j, j+2)) return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (not isValidPortion(board, i, i, 0, 8)) return false;
            if (not isValidPortion(board, 0, 8, i, i)) return false;
        }

        return true;
    }
};