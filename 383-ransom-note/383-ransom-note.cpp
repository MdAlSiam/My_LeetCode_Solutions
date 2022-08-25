class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int magFreq[26], noteFreq[26];

        for (int i = 0; i < 26; i++) {
            magFreq[i] = 0;
            noteFreq[i] = 0;
        }

        for (char ch : ransomNote) {
            noteFreq[ch-'a']++;
        }

        for (char ch : magazine) {
            magFreq[ch-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (noteFreq[i] > magFreq[i]) return false;
        }

        return true;
    }
};