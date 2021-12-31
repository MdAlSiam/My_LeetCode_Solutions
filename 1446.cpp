class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        int k = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) k = 0;
            k++;
            ans = max(ans, k);
        }
        
        return ans;
    }
};