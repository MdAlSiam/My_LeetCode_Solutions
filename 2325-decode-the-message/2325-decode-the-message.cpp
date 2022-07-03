class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mp;

        mp[' '] = ' ';

        char curr = 'a';

        for (char ch : key) {
            if (mp.count(ch)) {
                continue;
            }

            mp[ch] = curr;
            curr++;
        }

        string ans = "";

        for (char mm : message) {
            ans += mp[mm];
        }

        return ans;
    }
};