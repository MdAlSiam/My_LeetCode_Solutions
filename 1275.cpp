class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int grid[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = -1;
            }
        }

        bool a = true;

        for (vector<int> move : moves) {
            if (a) grid[move[0]][move[1]] = 1;
            else grid[move[0]][move[1]] = 0;
            a = not a;
        }

        // Check by row
        for (int i = 0; i < 3; i++) {
            int k0 = 0, k1 = 0;
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0) k0++;
                else if (grid[i][j] == 1) k1++;
            }
            if (k0 == 3) return "B";
            else if (k1 == 3) return "A";
        }

        // Check by column 
        for (int j = 0; j < 3; j++) {
            int k0 = 0, k1 = 0;
            for (int i = 0; i < 3; i++) {
                if (grid[i][j] == 0) k0++;
                else if (grid[i][j] == 1) k1++;
            }
            if (k0 == 3) return "B";
            else if (k1 == 3) return "A";
        }

        // Check diagonally
        if (grid[1][1] != -1) {
            if (grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2])  {
                if (grid[0][0] == 0) return "B";
                else return "A";
            }
            if (grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0])  {
                if (grid[0][2] == 0) return "B";
                else return "A";
            }
        }

        if (moves.size() < 9) return "Pending";
        else return "Draw";
    }
};