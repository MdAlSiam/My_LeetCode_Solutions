class Solution {
public:
    int climbStairs(int n) {
        long long int ara[max(5, n+1)];
        for (long long int i = 0; i <= n; i++) ara[i] = 0;

        ara[0] = 0;
        ara[1] = 1;
        ara[2] = 2;

        for (long long int i = 3; i <= n; i++) {
            ara[i] += ara[i-1]+ara[i-2];
        }

        return (int) ara[n];
    }
};