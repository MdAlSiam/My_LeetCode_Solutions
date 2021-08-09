#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) { 
            int toAdd = num2.size() - num1.size();

            for (int i = 0; i < toAdd; i++) num1 = '0'+num1;
        }
        else {
            int toAdd = num1.size() - num2.size();

            for (int i = 0; i < toAdd; i++) num2 = '0'+num2;
        }

        string ans = "";
        for (int i = 0; i <= num1.size(); i++) ans += '0';

        for (int i = num1.size()-1; i >= 0; i--) {
            int d1 = num1[i]-'0';
            int d2 = num2[i]-'0';
            int d3 = ans[i+1]-'0';
            int sum = d1+d2+d3;
            
            // c1 - c0 =  1
            // => c1 = 1 + c0

            ans[i+1]  = (sum%10)+'0';
            ans[i] = (sum/10)+'0';

            // cout << "Sum = " << sum << " > " << ans[i+1] << " " << ans[i] << endl;
        }

        cout << "Ans >> " << ans << endl;

        string ret = "";

        for (int i = 0; i < ans.size(); i++) {
            if (i == 0 and ans[0] == '0') continue;
            ret += ans[i];
        }
        
        return ret;
    }
};

int main() {
    // Problem Link: https://leetcode.com/problems/add-strings/
} 