class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string made = "";
        for (string word : words) {
            made += word;
            if (made == s) return true;
        }
        return false;
    }
};