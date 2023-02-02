class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, char> mp;
        char currChar = 'a';
        for (char ch : order) {
            mp[ch] = currChar++;
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                words[i][j] = mp[words[i][j]];
            }
        }

        for (int i = 1; i < words.size(); i++) {
            if (words[i-1] > words[i]) return false;
        }

        return true;
    }
};