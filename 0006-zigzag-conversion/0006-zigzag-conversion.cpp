class Solution {
public:
    string convert(string str, int numRows) {
        if (numRows == 1) return str;
        string ans = "";
        for (int ro = 0; ro < numRows; ro++) {
            int ahead = (numRows-1)*2;

            for (int i = ro; i < str.length(); i += ahead) {
                ans += str[i];
                if (ro > 0 and ro < numRows-1) {
                    if (i+ahead-ro*2 < str.length()) {
                        ans += str[i+ahead-ro*2];
                    }
                }
            }
        }
        return ans;
    }
};