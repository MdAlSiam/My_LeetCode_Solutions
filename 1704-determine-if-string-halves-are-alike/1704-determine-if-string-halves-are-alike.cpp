class Solution {
    bool isVowel(char ch) {
        char chars[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for (char cha : chars) {
            if (cha == ch) return true;
        }

        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int prefixCount = 0;
        int suffixCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length()/2) {
                if (isVowel(s[i])) prefixCount++;
            }
            else {
                if (isVowel(s[i])) suffixCount++;
            }
        }

        return prefixCount == suffixCount;
    }
};