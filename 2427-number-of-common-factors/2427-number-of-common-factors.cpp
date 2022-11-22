class Solution {
public:
    int commonFactors(int a, int b) {
        if (a > b) swap(a, b);
        int ans = 0;
        for (int i = 1; i*i <= a; i++) {
            if (a % i == 0) {
                int n1 = i;
                int n2 = a/i;

                if (b % n1 == 0) ans++;
                if (n1 != n2 and b % n2 == 0) ans++;
            }
        }

        return ans;
    }
};