class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        mat = vector<vector<int>> (m+1, vector<int>(n+1, 0));

        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                mat[i][j] = mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;

        return mat[row2][col2]-mat[row1-1][col2]-mat[row2][col1-1]+mat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */