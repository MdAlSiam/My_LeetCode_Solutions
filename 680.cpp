class Solution {
    bool isPalindrome(string s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++;
                hi--;
            }
            else {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int lo = 0;
        int hi = s.length()-1;

        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++;
                hi--;
            }
            else {
                return isPalindrome(s, lo+1, hi) or isPalindrome(s, lo, hi-1);
            }
        }

        return true;
    }
};
