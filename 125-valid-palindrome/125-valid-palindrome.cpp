class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        for (int i = 0; i < s.length(); i++) {
            // capital 
            if ('A' <= s[i] and s[i] <= 'Z') {
                str += s[i]-'A'+'a';
            }
            // smaller
            else if ('a' <= s[i] and s[i] <= 'z') {
                str += s[i];
            }
            else if ('0' <= s[i] and s[i] <= '9') {
                str += s[i];
            }
            // others

        }

        // ababa

        int lo = 0;
        int hi = str.length()-1;

        while (lo < hi) {
            if (str[lo] != str[hi]) {
                return false;
            }

            lo++;
            hi--;
        }

        return true;
    }
};