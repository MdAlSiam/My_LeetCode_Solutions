class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        if (str1+str2 == str2+str1) {
            ans = str1.substr(0, __gcd((int)str1.length(), (int)str2.length()));
        }
        return ans;
    }
};