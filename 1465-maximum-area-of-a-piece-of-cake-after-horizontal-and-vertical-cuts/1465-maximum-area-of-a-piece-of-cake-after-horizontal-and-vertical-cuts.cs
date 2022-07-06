public class Solution {
    public int MaxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        horizontalCuts = horizontalCuts.Append(0).ToArray();
        verticalCuts = verticalCuts.Append(0).ToArray();
        horizontalCuts = horizontalCuts.Append(h).ToArray();
        verticalCuts = verticalCuts.Append(w).ToArray();

        Array.Sort(horizontalCuts);
        Array.Sort(verticalCuts);

        long maxHorizSeg = 0;
        long maxVertSeg = 0;


        for (int i = 1; i < horizontalCuts.Length; i++) {
            maxHorizSeg = Math.Max(maxHorizSeg, horizontalCuts[i]-horizontalCuts[i-1]);
        }

        for (int i = 1; i < verticalCuts.Length; i++) {
            maxVertSeg = Math.Max(maxVertSeg, verticalCuts[i]-verticalCuts[i-1]);
        }

        long mod = 1_000_000_007;
        
        long ans = ((maxHorizSeg%mod)*(maxVertSeg%mod))%mod;

        return (int) ans;
    }
}