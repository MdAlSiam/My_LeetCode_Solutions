class Solution {
public:
    bool isThree(int n) {
        int kount = 0;
        for (int i = 1; i <= n; i++) {
            if (n%i == 0) {
                kount++;
            }
        }
        return kount==3;
    }
};