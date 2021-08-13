#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int roStatus[matrix.size()];
        int colStatus[matrix[0].size()];
        memset(roStatus, -1, sizeof(roStatus));
        memset(colStatus, -1, sizeof(colStatus));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    roStatus[i] = 0;
                    colStatus[j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (roStatus[i] == 0 or colStatus[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    
} 