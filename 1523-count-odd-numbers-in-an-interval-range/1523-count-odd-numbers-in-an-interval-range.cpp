class Solution {
public:
    int countOdds(int low, int high) {
        int kountUnTillLow = low/2;
        int kountTillHigh = (high+1)/2;
        
        return kountTillHigh - kountUnTillLow;
    }
};