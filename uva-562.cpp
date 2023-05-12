#include <bits/stdc++.h>
using namespace std;

int n;
int ara[120];
int total;
int ans;

int dp[101][50003];

int go(int index, int sum) {
    if (index >= n) {
        int p1 = sum;
        int p2 = total-sum;
        int diff = abs(p1-p2);
        ans = min(diff, ans);
        return ans;
    }

    if (dp[index][sum] != -1) return dp[index][sum];

    int x = go(index+1, sum+ara[index]);
    int y = go(index+1, sum);
    return dp[index][sum] = min(x, y);
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        total = 0;
        ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
            total += ara[i];
        }

        go(0, 0);

        cout << ans << endl;
    }
}
