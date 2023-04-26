class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;

        int sum = 0;
        int curr = num;

        while (curr != 0) {
            sum += (curr%10);
            curr /= 10;
        }

        if (sum%9 == 0) return 9;
        else return sum%9;
    }
};