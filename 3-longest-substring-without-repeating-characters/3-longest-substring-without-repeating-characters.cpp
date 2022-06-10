class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;

        int ans = 0;
        int curr = 0;
        int startFrom = 0;

        for (int i = 0; i < s.length(); i++) {
            if (not mp.count(s[i])) {
                curr++;
                mp[s[i]] = i;
            }
            else {
                //       3         8
                // p p p a x x x x a b c
                startFrom = max(startFrom, mp[s[i]]);
                curr = i-startFrom;
                mp[s[i]] = i;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};