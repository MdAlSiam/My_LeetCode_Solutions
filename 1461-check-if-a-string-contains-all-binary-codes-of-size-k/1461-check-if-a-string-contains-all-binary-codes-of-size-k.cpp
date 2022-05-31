class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;
        
        set<string> st;
        
        for (int i = 0; i+k <= s.length(); i++) {
            string curr = "";
            for (int j = 0; j < k; j++) {
                curr += s[i+j];
            }
            
            st.insert(curr);          
        }

        return st.size() == pow(2,k);
    }
};