// LeetCode 91: Decode Ways

class Solution {
public:
    int numDecodings(string s) {
        string str = "#"+s;
        int dp[str.length()];
        for (int i = 0; i < str.length(); i++) dp[i] = 0;
        dp[0] = 1;

        for (int i = 0; i < str.length(); i++) {
            if (i+1 < str.length() and str[i+1] >= '1' and str[i+1] <= '9') dp[i+1] += dp[i];
            if (i+2 < str.length() and str[i+1] == '1' and str[i+2] <= '9') dp[i+2] += dp[i];
            if (i+2 < str.length() and str[i+1] == '2' and str[i+2] <= '6') dp[i+2] += dp[i];
        }

        return dp[str.length()-1];
    }
};