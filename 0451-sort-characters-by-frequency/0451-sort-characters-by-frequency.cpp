class Solution {
    bool isUpperCase(char ch) {
        return ch >= 'A' and ch <= 'Z';
    }

    bool isDigit(char ch) {
        return ch == '0' or ch == '1' or ch == '2' or ch == '3' or ch == '4' or ch == '5'
                         or ch == '6' or ch == '7' or ch == '8' or ch == '9';
    }

    struct character
    {
        char ch;
        int freq;
    };

    static bool compare(character a, character b) {
        if (a.freq == b.freq) {
            return a.ch < b.ch;
        }
        return a.freq > b.freq;
    }
    
public:
    string frequencySort(string s) {
        character characters[26+26+10];
        for (int i = 0; i < 26; i++) {
            characters[i].ch = (char) (i+'a');
            characters[i].freq = 0;
        }
        for (int i = 26; i < 26+26; i++) {
            characters[i].ch = (char) (i+'A'-26);
            characters[i].freq = 0;
        }
        for (int i = 26+26; i < 26+26+10; i++) {
            characters[i].ch = (char) (i+'0'-26-26);
            characters[i].freq = 0;
        }

        for (char ch : s) {
            if (isUpperCase(ch)) {
                characters[ch-'A'+26].freq++;
            }
            else if (isDigit(ch)) {
                characters[ch-'0'+26+26].freq++;
            }
            else {
                characters[ch-'a'].freq++;
            }
        }

        sort(characters, characters+26+26+10, compare);

        string ans = "";

        for (int i = 0; i < 26+26+10; i++) while (characters[i].freq--) ans += characters[i].ch;

        return ans;
    }
};