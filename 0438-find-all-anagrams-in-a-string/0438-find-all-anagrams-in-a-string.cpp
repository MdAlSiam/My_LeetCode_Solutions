class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq_p(26, 0);
        vector<int> window(26, 0);
        vector<int> ans;
        ans.clear();

        if (s.length() < p.length()) return ans;

        for (int i = 0; i < p.length(); i++) {
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        if (freq_p == window) ans.push_back(0);

        for(int i = p.length(); i < s.length(); i++){
            window[s[i-p.length()]-'a']--;
            window[s[i]-'a']++;

            if (freq_p == window) ans.push_back(i-p.length()+1);
        }

        return ans;
    }      
};