#include <bits/stdc++.h>
using namespace std;

class Solution {
    int* dp;
public:
    int minCut(string s) {
        dp = new int[s.length()+1];
        
        for (int i = 0; i <= s.length(); i++) dp[i] = i-1;

        for (int k = 0; k < s.length(); k++) {
            int i = k;
            int j = k;
            
            while (i >= 0 and j < s.length() and s[i] == s[j]) {
                dp[j+1] = min(dp[j+1], dp[i]+1);
                i--;
                j++;
            }

            i = k-1;
            j = k;

            while (i >= 0 and j < s.length() and s[i] == s[j]) {
                dp[j+1] = min(dp[j+1], dp[i]+1);
                i--;
                j++;
            }
        }

        return dp[s.length()];
    }
};

int main() {
    // https://leetcode.com/problems/palindrome-partitioning-ii/    
}