class Solution {
public:
    int partitionString(string s) {
        int ans = 1;
        map<char, int> mp;
        mp.clear();

        for (int i = 0; i < s.length(); i++) {
            if (mp.count(s[i])) {
                mp.clear();
                ans++;
            }

            mp[s[i]] = 1;
        }

        return ans;
    }
};