class Solution {
public:
    int firstUniqChar(string s) {
        int first[26];
        for (int i = 0; i < 26; i++) first[i] = -1;

        for (int i = 0; i < s.length(); i++) {
            if (first[s[i]-'a'] == -69) continue;
            else if (first[s[i]-'a'] != -1) {
                first[s[i]-'a'] = -69;
            }
            else {
                first[s[i]-'a'] = i;
            }
        }

        int ans = 199999;

        for (int i = 0; i < 26; i++) {
            if (first[i] < 0) continue;
            ans = min(ans, first[i]);
        }
        
        if (ans == 199999) return -1;

        return ans;
    }
};