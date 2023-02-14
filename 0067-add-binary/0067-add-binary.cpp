class Solution {
public:
    string addBinary(string a, string b) {
        int index1 = a.size() - 1;
        int index2 = b.size() - 1;
        
        string ans = "";
        
        int carry = 0;
        
        while (index1 >= 0 or index2 >= 0) {
            int sum = 0;
            
            if (index1 >= 0 and index2 >= 0) sum = a[index1]-'0'+b[index2]-'0'+carry;
            else if (index1 >= 0) sum = a[index1]-'0'+carry;
            else if (index2 >= 0) sum = b[index2]-'0'+carry;
            
            carry = 0;
            
            if (sum >= 2) {
                if (sum%2 == 0) ans += '0';
                else ans += '1';
                carry = 1;
            }
            else if (sum == 1) {
                ans += '1';
            }
            else {
                ans += '0';
            }
            
            index1--;
            index2--;
        }
        if (carry) ans += '1';
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};