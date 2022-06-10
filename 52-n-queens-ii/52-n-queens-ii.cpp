class Solution {
    int n; 

    int ans = 0;

    int* ro_for_col;

    void init_ro_for_col() {
        ro_for_col = new int[n];
        for (int i = 0; i < n; i++) ro_for_col[i] = -1;
    }

    bool isSafe(int ro, int col) {
        // same row
        for (int c = col; c >= 0; c--) if (ro_for_col[c] == ro) return false;

        // same diag
        for (int r = ro, c = col; r >= 0 and c >= 0; r--, c--) if (ro_for_col[c] == r) return false;

        // same anti-diag
        for (int r = ro, c = col; r < n and c >= 0; r++, c--) if (ro_for_col[c] == r) return false;

        return true;
    }

    void solve(int curr_col) {
        // base
        if (curr_col == n) {
            ans++;
            return;
        }

        // Try every row in this column
        for (int ro = 0; ro < n; ro++) {
            if (isSafe(ro, curr_col)) {
                ro_for_col[curr_col] = ro;
                solve(curr_col+1);
                ro_for_col[curr_col] = -1;
            }
        }
    }
public:
    int totalNQueens(int _n) {
        n = _n;

        init_ro_for_col();

        solve(0);

        return ans;
    }
};