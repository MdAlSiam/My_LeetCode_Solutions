class Solution {
    bool isValidPortion(vector<vector<int>>& matrix, int roBegin, int roEnd, int colBegin, int colEnd) {
        set<int> st;

        for (int i = roBegin; i <= roEnd; i++) {
            for (int j = colBegin; j <= colEnd; j++) {
                st.insert(matrix[i][j]);
            }
        }

        return matrix.size() == st.size();
    }
public:
    bool checkValid(vector<vector<int>>& matrix) {
        bool ans = true;

        for (int ro = 0; ro < matrix.size(); ro++) 
            ans &= isValidPortion(matrix, ro, ro, 0, matrix[ro].size()-1);
        for (int col = 0; col < matrix[0].size(); col++) 
            ans &= isValidPortion(matrix, 0, matrix[col].size()-1, col, col);
            
        return ans;
    }
};