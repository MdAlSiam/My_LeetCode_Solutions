class Solution {
    string codes[26] = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
        "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };

    string make_code(string str) {
        string ret = "";
        for (char ch : str) {
            ret += codes[ch-'a'];
        }
        return ret;
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;

        for (string str : words) {
            st.insert(make_code(str));
        }

        return (int) st.size();
    }
};