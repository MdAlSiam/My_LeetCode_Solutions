// Problem Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string/
class Solution {
public:
    string makeFancyString(string s) {
        int same = 1;
        s += "#";
        string ans = "";
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) same++;
            else {
                if (same <= 2);
                else same = 2;
                
                while (same--) ans += s[i-1];
                same = 1;
            }
        }
        return ans;
    }
};
