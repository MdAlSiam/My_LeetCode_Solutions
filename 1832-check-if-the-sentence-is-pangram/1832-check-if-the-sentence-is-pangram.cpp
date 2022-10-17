class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool present[26];
        for (int i = 0; i < 26; i++) present[i] = false;
        
        for (char ch : sentence) {
            present[ch-'a'] = true;
        }
        
        for (int i = 0; i < 26; i++) {
            if (not present[i]) return false;
        }
        
        return true;
    }
};