class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;

        int ans = 0;
        int curr = 0;

        for (int i = 0; i < s.length(); i++) {
            if (not mp.count(s[i])) {
                curr++;
                mp[s[i]] = i;
            }
            else {
                //       3         8
                // p p p a x x x x a b c
                curr = i-mp[s[i]];
                int startsNow = mp[s[i]]+1;
                mp.clear();
                for (int j = startsNow; j <= i; j++) mp[s[j]] = j;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};