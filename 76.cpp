// LeetCode 76: Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> kount_tt;
        for (auto ch : t) {
            kount_tt[ch]++;
        }

        int distinct = kount_tt.size();

        map<char, int> kount_window;

        int distint_found = 0 , anslo = 0 , anshi = 0;

        int left = 0, right = 0; 

        int maxi = INT_MAX;

        while (right < s.length()) {
            kount_window[s[right]]++;

            if (kount_tt.count(s[right]) and kount_tt[s[right]] == kount_window[s[right]]) {
                distint_found++;
            }

            right++;

            while (distint_found == distinct and left < right) {
                if (maxi > right-left) {
                    maxi = right-left;
                    anslo = left;
                    anshi = right;
                }

                kount_window[s[left]]--;              
                if(kount_tt.count(s[left]) and kount_window[s[left]] < kount_tt[s[left]]) {
                    distint_found--;
                }

                left++;
            }
        }

            
        string ans = "";
        if (anslo < 0) return ans;
        for (int i = anslo; i < anshi; i++) ans += s[i];
        return ans;
    }
};