public class Solution {
    public int Fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        int prev2 = 0;
        int prev1 = 1;
        
        for (int i = 2; i <= n; i++) {
            int fib = prev1+prev2;
            
            if (i == n) {
                return fib;
            }
            
            prev2 = prev1;
            prev1 = fib;
        }
        
        return 0;
    }
}