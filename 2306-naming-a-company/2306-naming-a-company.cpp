class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<set<string>> suffixes(26);
        for (string str : ideas) {
            string substr = str.substr(1);
            suffixes[str[0]-'a'].insert(substr);
        }

        long long int ans = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = i+1; j < 26; j++) {
                int nCommon = 0;
                for (set<string>::iterator it = suffixes[i].begin(); it != suffixes[i].end(); it++) {
                    string str = *it;
                    if(suffixes[j].count(str)) nCommon++; 
                } 
                ans += 2*(suffixes[i].size()-nCommon)*(suffixes[j].size()-nCommon);
            }
        }

        return ans;
    }
};