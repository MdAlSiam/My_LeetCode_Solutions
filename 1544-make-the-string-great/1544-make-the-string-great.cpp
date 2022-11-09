class Solution {
    char findOppositeCase(char ch) {
        if (ch >= 'A' and ch <= 'Z') return (char) ch-'A'+'a';
        else return (char) ch-'a'+'A';
    }
public:
    string makeGood(string s) {
        stack<char> st;

        st.push(s[0]);

        for (int i = 1; i < s.length(); i++) {
            if (!st.empty() and findOppositeCase(st.top()) == s[i]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};