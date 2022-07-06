public class Solution {
    string s1 = "";
    string s2 = "";
    string s3 = "";

    int[,] dp = new int[,] {{}};

    bool go(int i, int j, int k) {
        // Console.WriteLine(">>"+i+" "+j+" "+k);
        if (dp[i,j] != -1) {
            return dp[i,j] == 1 ? true : false;
        }
        
        if (i == s1.Length && j == s2.Length && k == s3.Length) {
            return true;
        }

        bool ret1 = false;
        bool ret2 = false;

        if (i < s1.Length && k < s3.Length && s1[i] == s3[k]) {
            ret1 = go(i+1, j, k+1);
        }

        if (j < s2.Length && k < s3.Length && s2[j] == s3[k]) {
            ret2 = go(i, j+1, k+1);
        }

        bool ret = ret1 || ret2;

        if (ret) dp[i,j] = 1;
        else dp[i,j] = 0;

        return ret;
    }

    public bool IsInterleave(string _s1, string _s2, string _s3) {
        s1 = _s1;
        s2 = _s2;
        s3 = _s3;

        dp = new int[s1.Length+1,s2.Length+1];
        for (int i = 0; i <= s1.Length; i++) {
            for (int j = 0; j <= s2.Length; j++) {
                dp[i,j] = -1;
            }
        }

        return go(0, 0, 0);
    }
}