class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int finalLo = 0, finalHi = 0, lo = 0, hi = 0, finalLen = 1;
        for (int i = 0; i < n; i++) {
            lo = i;
            hi = i;
            while (lo-1 >= 0 and s[lo-1] == s[i]) lo--;
            while (hi+1 < n and s[hi+1] == s[i]) hi++;
            while (lo-1 >= 0 and hi+1 < n and s[lo-1] == s[hi+1]) lo--, hi++;

            int len = hi-lo+1;
            if (len > finalLen) {
                finalLen = len;
                finalLo = lo;
                finalHi = hi;
            }
        }

        string ans = "";
        for (int i = finalLo; i <= finalHi; i++) ans += s[i];

        return ans;
    }
};