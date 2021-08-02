#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        // int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        // int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        bool visited[grid.size()][grid[0].size()];
        memset(visited, false, sizeof(visited));

        int inf = 10000000;

        int gridIds[grid.size()][grid[0].size()];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                gridIds[i][j] = inf;
            }
        }

        int gridId = 0;
        vector<int> sizeForId;
        sizeForId.clear();

        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                if (not visited[i][j]) {
                    int sizeHere = 0;

                    queue<pair<int, int> > q;
                    queue<pair<int, int> > q2;

                    q.push({i, j});
                    q2.push({i, j});
                    visited[i][j] = true;
                    sizeHere++;

                    while (!q.empty()) {
                        int xx = q.front().first;
                        int yy = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int newx = xx+dx[k];
                            int newy = yy+dy[k];
                            
                            if (newx >= 0 and newx < grid.size() and newy >= 0 and newy < grid[0].size() and visited[newx][newy] == false) {
                                if (grid[newx][newy] == 1) {
                                    q.push({newx, newy});
                                    q2.push({newx, newy});
                                    visited[newx][newy] = true;
                                    sizeHere++;
                                }
                            }
                        }
                    }

                    if (!q2.empty()) {
                        sizeForId.push_back(q2.size());
                        while (!q2.empty()) {
                            int xxx = q2.front().first;
                            int yyy = q2.front().second;
                            // printf("> %d %d >> %d\n", xxx, yyy, gridId);
                            gridIds[xxx][yyy] = gridId;
                            q2.pop();
                        }
                        gridId++;
                    }
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // printf("%d ~ ", gridIds[i][j]);
            }
            // printf("\n");
        }
 
        for (int i = 0; i < sizeForId.size(); i++) {
            // printf("# %d ", sizeForId[i]);
            ans = max(ans, sizeForId[i]);
        }
        // printf("!\n");

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    vector<int> idsHere;
                    idsHere.clear();
                    for (int k = 0; k < 4; k++) {
                        int newx = i+dx[k];
                        int newy = j+dy[k];
                        
                        if (newx >= 0 and newx < grid.size() and newy >= 0 and newy < grid[0].size()) {
                            if (gridIds[newx][newy] != inf) {
                                idsHere.push_back(gridIds[newx][newy]);
                            }
                        }
                    }
                    int ansHere = 1;
                    sort(idsHere.begin(), idsHere.end());
                    
                    for (int id_index = 0; id_index < idsHere.size(); id_index++) {
                        // printf("^%d %d )  %d -> %d\n", i, j, idsHere[id_index], sizeForId[idsHere[id_index]]);
                        if (id_index > 0 and idsHere[id_index-1] == idsHere[id_index]) continue;
                        ansHere += sizeForId[idsHere[id_index]];
                    }
                    // printf(" OK\n");
                    
                    ans = max(ans, ansHere);
                    // printf("AnsHere = %d, Ans = %d\n", ansHere, ans);
                }
            }
        }

        return ans;
    }
};


int main() {
    // Call whatever it requires according to the defined class above
    // Problem Link: https://leetcode.com/problems/making-a-large-island/
}