// Link: https://leetcode.com/problems/longest-uncommon-subsequence-ii/

class Solution {
bool isSubsequence(string subseqholder, string subseqcandidate) {
    int pointer = 0;
    for (int i = 0; i < subseqcandidate.size(); i++) {        
        while (true) {
            if (pointer >= subseqholder.size()) return false;
            if (subseqholder[pointer] == subseqcandidate[i]) {
                pointer++;
                break;
            }
            pointer++;
        }
    }

    return true;
}

public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), 
            [](const auto &a, const auto &b) {
                if (a.size() == b.size()) return a < b;
                return a.size() > b.size();
            }
        );

        int ans = -1;

        for (int i = 0; i < strs.size(); i++) {
            if (i+1 < strs.size() and strs[i] == strs[i+1]) continue;
            if (i-1 >= 0 and strs[i-1] == strs[i]) continue;

            bool update = true;

            for (int j = 0; j < i; j++) {
                if (isSubsequence(strs[j], strs[i])) {
                    update = false;
                    break;
                }
            }

            if (update) ans = strs[i].size();

            if (ans != -1) break;
        }

        return ans;
    }
};