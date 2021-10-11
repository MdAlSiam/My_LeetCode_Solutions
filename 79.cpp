class Solution {
    vector<vector<bool>> seen;

    void initiate_seen(int n, int m) {
        for (int i = 0; i < seen.size(); i++) seen[i].clear();

        for (int i = 0; i < n; i++) {
            vector<bool> row;
            for (int j = 0; j < m; j++) {
                row.push_back(false);
            }
            seen.push_back(row);
        }
    }

    bool goFrom(vector<vector<char>>& board, string word, int index, int i, int j) {
        if (index >= word.size()) return false;

        if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size()) return false;
        
        if (board[i][j] != word[index]) return false;

        if (index == word.size()-1) return true;

        char hash = board[i][j];
        board[i][j] = '#';

        bool r1 = goFrom(board, word, index+1, i+1, j);
        bool r2 = goFrom(board, word, index+1, i-1, j);
        bool r3 = goFrom(board, word, index+1, i, j+1);
        bool r4 = goFrom(board, word, index+1, i, j-1);

        board[i][j] = hash;

        return r1|r2|r3|r4;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // initiate_seen(board.size(), board[0].size());
                ans = goFrom(board, word, 0, i, j);
                if (ans) return ans;
            }
        }
        return ans;
    }
};