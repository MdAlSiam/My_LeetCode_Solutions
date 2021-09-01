// Problem Link: https://leetcode.com/problems/sudoku-solver/

class Solution {
public: 
    bool isValid(vector<vector<char>>& board, int i, int j, char& ch) {
        for (int col = 0; col < 9; col++) {
            if (board[i][col] == ch) return false;
        }

        for (int ro = 0; ro < 9; ro++) {
            if (board[ro][j] == ch) return false;
        }

        int ro_start = (i/3)*3;
        int col_start = (j/3)*3;

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[k+ro_start][l+col_start] == ch) return false;
            }
        }
        
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;

        if (j == 9) return backtrack(board, i+1, 0);

        if (board[i][j] != '.') return backtrack(board, i, j+1);
        
        for (char ch = '1'; ch <= '9'; ch++) {
            if (isValid(board, i, j, ch)) {
                board[i][j] = ch;
                if (backtrack(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};