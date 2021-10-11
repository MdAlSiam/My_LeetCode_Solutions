class Solution {
public:
    string breakPalindrome(string palindrome) {

        if (palindrome.length() == 1) return "";

        int lo = 0;
        int hi = palindrome.length()-1;

        bool done = false;

        while (lo <= hi) {
            if (palindrome[lo] != 'a') {
                char prev = palindrome[lo];
                palindrome[lo] = 'a';
                if (palindrome[lo] != palindrome[hi]) {
                    done = true;
                }
                else {
                    palindrome[lo] = prev;
                }
                break;
            }
            lo++;
            hi--;
        }

        if (done) return palindrome;

        lo = 0;
        hi = palindrome.length()-1;

        while (lo <= hi) {
            if (palindrome[lo] > 'b') {
                char prev = palindrome[lo];
                palindrome[lo] = 'b';
                if (palindrome[lo] != palindrome[hi]) {
                    done = true;
                }
                else {
                    palindrome[lo] = prev;
                }
                break;
            }
            lo++;
            hi--;
        }

        if (done) return palindrome;

        for (int i = palindrome.length()-1; i >= 0; i--) {
            if (palindrome[i] == 'a') {
                palindrome[i] = 'b';
                break;
            }
        }

        return palindrome;
    }
};