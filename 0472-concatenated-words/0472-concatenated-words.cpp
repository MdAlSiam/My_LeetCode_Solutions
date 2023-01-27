class Solution {
    map<string, bool> mp;
    map<string, bool> formed;

    bool isPossible(string word) {
        if (formed[word]) return true;

        for (int i = 1; i < word.length(); i++) {
            string s1 = word.substr(0, i);
            string s2 = word.substr(i);

            if (mp[s1] and (mp[s2] or isPossible(s2))) {
                formed[word] = true;
                return true;
            }
        }

        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string word : words) mp[word] = true;
        vector<string> ans;
        for (string word : words) {
            if (isPossible(word)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};