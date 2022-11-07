class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        
        while (num > 0) {
            digits.push_back(num%10);
            num /= 10;
        }
        
        int ans = 0;
        
        bool doneOnce = false;
        
        for (int i = digits.size()-1; i >= 0; i--) {
            if (not doneOnce and digits[i] == 6) {
                digits[i] = 9;
                doneOnce = true;
            }
            
            ans *= 10;
            ans += digits[i];
        }
        
        return ans;
    }
};