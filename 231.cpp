class Solution {
    long long int nOneBits(long long int n) {
        long long int ret = 0;
        for (long long int i = 0; i < 32; i++) {
            if (n & (1LL<<i)) ret++;
        }

        return ret;
    }
public:
    bool isPowerOfTwo(long long int n) {
        if (n < 0) return false;
        return nOneBits(n) == 1;
    }
};