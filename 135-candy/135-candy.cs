public class Solution {
    public int Candy(int[] ratings) {
        int n = ratings.Length;

        int[] res = new int[n];

        Array.Fill(res, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1] && res[i] <= res[i-1]) {
                res[i] = res[i-1]+1;
            }
        }

        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && res[i] <= res[i+1]) {
                res[i] = res[i+1]+1;
            }
        }

        return res.Sum();
    }
}