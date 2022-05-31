class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length()) return false;
        
        bool present[1<<k];
        memset(present, false, sizeof(present));
        
        int last_k_bits_mask = (1<<k)-1;
        
        int curr = 0;
        for (int i = 0; i < k-1; i++) {
            curr <<= 1;
            if (s[i] == '1') curr |= 1;
        }
        
        for (int i = k-1; i < s.length(); i++) {
            curr <<= 1;
            if (s[i] == '1') curr |= 1;
            curr &= last_k_bits_mask;
            present[curr] = true;
        }
        
        for (int i = 0; i < (1<<k); i++) {
            if (not present[i]) {
                return false;
            }
        }
        
        return true;
    }
};


// Idea Credit: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/2093054/O(n)-Bitwise-100-fast-oror-Easy-to-understand-C%2B%2B