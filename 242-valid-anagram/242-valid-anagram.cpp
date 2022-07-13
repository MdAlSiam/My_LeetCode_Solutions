class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq1[26];
        int freq2[26];
        
        for (int i = 0; i < 26; i++) {
            freq1[i] = 0;
            freq2[i] = 0;
        }
        
        for (char ch : s) {
            freq1[ch-'a']++;
        }
        
        for (char ch : t) {
            freq2[ch-'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        
        return true;
    }
};