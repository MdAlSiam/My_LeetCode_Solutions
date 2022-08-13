class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int winSize = words.size()*words[0].size();
        int wordSize = words[0].size();

        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        for (int i = 0; i+winSize <= s.length(); i++) { 
            unordered_map<string, int> new_mp;
            new_mp.clear();

            string temp = "";
            int kount = wordSize;
            for (int j = 0; j < winSize; j++) {
                temp += s[i+j];
                kount--;

                if (kount == 0) {
                    if (mp.count(temp)) {
                        new_mp[temp]++;
                        
                        temp = "";
                        kount = wordSize;
                    }
                    else {
                        break;
                    }
                }
                
            }

            bool ok = true;
            for (auto element : mp) {
                if (new_mp.count(element.first) and new_mp[element.first] == element.second);
                else {ok = false; break;}
            }

            if (ok) ans.push_back(i);
        }

        return ans;
    }
};