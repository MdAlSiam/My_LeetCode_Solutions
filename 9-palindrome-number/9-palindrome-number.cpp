class Solution {
    #define ll long long int
public:
    bool isPalindrome(int x) {
        /*
                12321

                1 2 3 2 1
                12321 = 12321

                12            3

                3 2 1
                321

                321 != 123
        */
        
        if (x < 0) return false;

        ll n = x;

        ll x2 = 0;

        while (n > 0) {
            ll digit = n%10;
            n /= 10;

            x2 *= 10;
            x2 += digit;
        }

        return x == x2;
    }
};