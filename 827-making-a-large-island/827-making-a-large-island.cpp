class Solution {
    int n;
    vector<vector<int>> g;
    vector<vector<int>> components;
    vector<int> componentSizes;

    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    bool isValid(int r, int c) {
        return 0 <= r and r < n and 0 <= c and c < n;
    }

    void dfs(int r, int c, int cval) {
        components[r][c] = cval;
        componentSizes[cval]++;

        for (int i = 0; i < 4; i++) {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if (isValid(nr, nc) and g[nr][nc] == 1 and components[nr][nc] == -1) {
                dfs(nr, nc, cval);
            }
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        g = grid;
        components = vector<vector<int>> (n, vector<int> (n, -1));
        componentSizes = vector<int> (n*n, 0);

        int ans = 0;

        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1 and components[i][j] == -1) {
                    dfs(i, j, c);
                    ans = max(ans, componentSizes[c]);
                    c++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] ==  0) {
                    vector<int> componenetsHere;
                    for (int d = 0; d < 4; d++) {
                        int ni = i+dr[d];
                        int nj = j+dc[d];

                        if (isValid(ni, nj) and g[ni][nj] == 1) {
                            componenetsHere.push_back(components[ni][nj]);
                        }
                    }

                    sort(componenetsHere.begin(), componenetsHere.end());
                    int ansHere = 1;
                    for (int d = 0; d < componenetsHere.size(); d++) {
                        if (d > 0 and componenetsHere[d-1] == componenetsHere[d]) continue;
                        ansHere += componentSizes[componenetsHere[d]];
                    }
                    
                    ans = max(ans, ansHere);
                }
            }
        }

        return ans;
    }
};