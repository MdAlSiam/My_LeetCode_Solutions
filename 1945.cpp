#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string getStringFromNum(int num) {
        vector<int> digits;
        digits.clear();
        while (num > 0) {
            int mod = num%10;
            digits.push_back(mod);
            num /= 10;
        } 

        string ret = "";

        for (int i = digits.size()-1; i >= 0; i--) {
            ret += (char)(digits[i]+'0');
        }
        
        return ret;
    }
public:
    int getLucky(string s, int k) {
        string init = "";
        for (int i = 0; i < s.length(); i++) {
            int nn = s[i]-'a'+1;
            init += getStringFromNum(nn);
        }
        
        int sum = 0;
        
        while (k--) {
            sum = 0;
            for (int i = 0; i < init.size(); i++) {
                sum += (init[i]-'0');
            }
            init =  getStringFromNum(sum);
        }
        
        return sum;
    }
};

int main() {
    // Instantiate and call whatever it takes
    // Or run here: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
}