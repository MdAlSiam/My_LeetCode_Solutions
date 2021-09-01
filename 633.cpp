// Link: https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(long long int c) {
        for (long long int i = 0LL; i*i <= c; i++) {
            long long int c1 = i*i;
            long long int c2 = (c-c1);
            if (c2 < 0LL) continue;
            long long int rootc2 = (int) sqrt(c2);
            if (rootc2*rootc2 == c2) return true;
        }
        return false;
    }
};