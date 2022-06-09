class Solution {
    bool isPalin(string str) {
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
public:
    int removePalindromeSub(string s) {
        int a = 0;
        int b = 0;
        for (char ch : s) {
            if (ch == 'a') a++;
            else b++;
        }
        
        if (isPalin(s)) return 1;
        else return 2;
        return 0;
    }
};