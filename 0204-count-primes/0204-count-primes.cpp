class Solution {
public:
    int countPrimes(int n) {
        bool isComposite[max(2, n+1)];
        for (int i = 1; i <= n; i++) isComposite[i] = false;

        isComposite[0] = isComposite[1] = true;

        for (int i = 2; i*i <= n; i++) {
            if (isComposite[i] == false) {
                for (int times = 2; i*times <= n; times++) {
                    isComposite[i*times] = true;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) if (isComposite[i] == false) ans++;
        return ans;
    }
};