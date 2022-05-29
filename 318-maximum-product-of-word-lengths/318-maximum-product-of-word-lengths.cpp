class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        // Time: 26*n
        // Space 26*n
        int grid[26][n];
        memset(grid, 0, sizeof(grid));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                grid[words[i][j]-'a'][i]++;
            }
        }

        // Time (n^2)*26
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                bool hasCommon = false;
                for (int k = 0; k < 26; k++) {
                    if (grid[k][i] and grid[k][j]) {
                        hasCommon = true;
                        break;
                    }
                }
                if (not hasCommon) {
                    int ansHere = words[i].length()*words[j].length();
                    ans = max(ans, ansHere);
                }
            }
        }

        return ans;
    }
};