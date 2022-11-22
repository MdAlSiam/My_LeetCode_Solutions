class Solution {
public:
    int countPrimes(int n) {
        bool isComposite[n/2 + 3];
        for (int i = 0; i < n/2 + 3; i++) isComposite[i] = false;     

        for (int i = 3; i*i <= n; i += 2) {
            if (isComposite[i/2] == false) {
                for (int times = i; i*times <= n; times += 2) {
                    isComposite[(i*times)/2] = true;
                }
            }
        }

        int ans = 0;
        if (n > 2) ans = 1;
        for (int i = 3; i < n; i += 2) if (isComposite[i/2] == false) ans++;
        return ans;
    }
};