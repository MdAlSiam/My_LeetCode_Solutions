class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        ans.clear();

        int curr_x = 0;
        int curr_y = 0;

        char curr_dir = 'R';

        while (true) {
            ans.push_back(matrix[curr_x][curr_y]);
            matrix[curr_x][curr_y] = 500;

            if (curr_dir == 'R') {
                if (curr_y+1 < matrix[0].size() and matrix[curr_x][curr_y+1] != 500) {
                    // right
                    curr_y++;
                    curr_dir = 'R';
                }
                else if (curr_x+1 < matrix.size() and matrix[curr_x+1][curr_y] != 500) {
                    // down
                    curr_x++;
                    curr_dir = 'D';
                }
                else {
                    break;
                }
            }
            else if (curr_dir == 'D') {
                if (curr_x+1 < matrix.size() and matrix[curr_x+1][curr_y] != 500) {
                    // down
                    curr_x++;
                    curr_dir = 'D';
                }
                else if (curr_y-1 >= 0 and matrix[curr_x][curr_y-1] != 500) {
                    // left
                    curr_y--;
                    curr_dir = 'L';
                }
                else {
                    break;
                }
            }
            else if (curr_dir == 'L') {
                if (curr_y-1 >= 0 and matrix[curr_x][curr_y-1] != 500) {
                    // left
                    curr_y--;
                    curr_dir = 'L';
                }
                else if (curr_x-1 >= 0 and matrix[curr_x-1][curr_y] != 500) {
                    // up
                    curr_x--;
                    curr_dir = 'U';
                }
                else {
                    break;
                }
            }
            else if (curr_dir == 'U') {
                if (curr_x-1 >= 0 and matrix[curr_x-1][curr_y] != 500) {
                    // up
                    curr_x--;
                    curr_dir = 'U';
                }
                else if (curr_y+1 < matrix[0].size() and matrix[curr_x][curr_y+1] != 500) {
                    // right
                    curr_y++;
                    curr_dir = 'R';
                }
                else {
                    break;
                }
            }
        }

        return ans;
    }
};