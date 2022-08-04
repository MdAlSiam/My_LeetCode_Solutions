class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = (p*q) / __gcd(p, q);
        if (lcm%(q+q) == 0) return 2;
        return (lcm/p)%2;
    }
};