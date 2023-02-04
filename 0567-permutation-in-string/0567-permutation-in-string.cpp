class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int charKount[26];
        int currWindowKount[26];
        for (int i = 0; i < 26; i++) charKount[i] = 0, currWindowKount[i] = 0;

        for (char ch : s1) charKount[ch-'a']++;

        for (int i = 0; i < s1.length(); i++) {
            currWindowKount[s2[i]-'a']++;
        }

        bool allPresent = true;
        for (int i = 0; i < 26; i++) {
            if (charKount[i] != currWindowKount[i]) {
                allPresent = false;
                break;
            }
        }
        if (allPresent) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            currWindowKount[s2[i-s1.length()]-'a']--;
            currWindowKount[s2[i]-'a']++;

            bool allPresent = true;
            for (int j = 0; j < 26; j++) {
                if (charKount[j] != currWindowKount[j]) {
                    allPresent = false;
                    break;
                }
            }
            if (allPresent) return true;
        }

        return false;
    }
};