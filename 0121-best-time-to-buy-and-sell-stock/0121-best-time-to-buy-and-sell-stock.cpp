class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = 1000000;

        int ans = 0;

        for (int price : prices) {
            ans = max(ans, max(0, price-minTillNow));
            minTillNow = min(minTillNow, price);
        }

        return ans;
    }
};