class Solution {
    long long int* tribonacci_num;

    void init() {
        tribonacci_num = new long long int[40];
        tribonacci_num[0] = 0;
        tribonacci_num[1] = 1;
        tribonacci_num[2] = 1;

        for (int i = 3; i < 40; i++) {
            tribonacci_num[i] = tribonacci_num[i-1]+tribonacci_num[i-2]+tribonacci_num[i-3];
        }
    }
public:
    int tribonacci(int n) {
        init();
        return tribonacci_num[n];
    }
};