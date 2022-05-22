class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        int center = 0;

        while (center < s.length()) {
            int lo = center;
            int hi = center;

            while (lo-1 >= 0 and s[center] == s[lo-1]) lo--;
            while (hi+1 < s.length() and s[center] == s[hi+1]) hi++;

            int len = hi-lo+1;
            ans += (len*(len+1))/2;

            lo--;
            hi++;

            center = hi;

            while (lo >= 0 and hi < s.length() and s[lo] == s[hi]) {
                ans++;
                lo--;
                hi++;
            }
        }

        return ans;
    }
};