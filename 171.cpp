class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());

        int ans = 0;
        int power = 0;

        for (char ch : columnTitle) {
            int digit = (int) 1+ch-'A';
            ans += digit*pow(26, power);

            power++;
        }

        return ans;
    }
};