// LeetCode 1967: Number of Strings That Appear as Substrings in Word

class Solution {
    bool isSubString(string original, string checking) {
        for (int i = 0; i < original.length(); i++) {
            bool foundthistime = true;
            for (int j = i; j-i < checking.length(); j++) {
                if (j >= original.length()) {
                    foundthistime = false;
                    break;
                }
                if (original[j] != checking[j-i]) {
                    foundthistime = false;
                    break;
                }
            }
            if (foundthistime) {
                return true;
            }
        }
        return false;
    }
    
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (string curr : patterns) {
            if (isSubString(word, curr)) ans++;
        }
        return ans;
    }
};  