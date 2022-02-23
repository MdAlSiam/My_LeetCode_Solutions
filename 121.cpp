class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxTillNow = -1;
        int minTillNow = 1000000;

        int ans = 0;

        for (int price : prices) {
            maxTillNow = max(maxTillNow, price);
            ans = max(ans, maxTillNow-minTillNow);
            minTillNow = min(minTillNow, price);
        }

        return ans;
    }
};