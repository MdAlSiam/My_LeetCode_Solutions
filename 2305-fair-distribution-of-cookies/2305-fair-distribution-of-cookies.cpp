class Solution {
    int ans;
    int k;
    void solve(int index, vector<int>& distribution, vector<int>& cookies) {
        if (index == cookies.size()) {
            int max_here = INT_MIN;
            for (int i = 0; i < k; i++) {
                max_here = max(max_here, distribution[i]);
            }
            ans = min(ans, max_here);
            return;
        }

        for (int i = 0; i < k; i++) {
            distribution[i] += cookies[index];
            solve(index+1, distribution, cookies);
            distribution[i] -= cookies[index];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int _k) {
        ans = INT_MAX;
        k = _k;
        vector<int> distribution(k, 0);
        solve(0, distribution, cookies);
        return ans;
    }
};