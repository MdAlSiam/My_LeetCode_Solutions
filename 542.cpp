#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = -1;
                }
                else {
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> xy = q.front();
            q.pop();

            int x = xy.first;
            int y = xy.second;

            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if (nx >= 0 and nx < mat.size() and ny >= 0 and ny < mat[0].size() and mat[nx][ny] == -1) {
                    mat[nx][ny] = min(mat[nx][ny], mat[x][y]+1);
                    q.push({nx, ny});
                }
            }
        }

        return mat;
    }
};

int main() {

}