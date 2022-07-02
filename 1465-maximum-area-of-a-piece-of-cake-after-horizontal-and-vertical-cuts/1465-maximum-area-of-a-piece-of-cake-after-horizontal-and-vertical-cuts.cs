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

        // Console.Write("Horizontals "+horizontalCuts[0]+" ");
        for (int i = 1; i < horizontalCuts.Length; i++) {
            maxHorizSeg = Math.Max(maxHorizSeg, horizontalCuts[i]-horizontalCuts[i-1]);
            // Console.Write(horizontalCuts[i]+" ");
        }
        // Console.WriteLine();

        // Console.Write("Verticals "+verticalCuts[0]+" ");
        for (int i = 1; i < verticalCuts.Length; i++) {
            maxVertSeg = Math.Max(maxVertSeg, verticalCuts[i]-verticalCuts[i-1]);
            // Console.Write(verticalCuts[i]+" ");
        }
        // Console.WriteLine();

        long mod = 1_000_000_007;
        
        // long ans = ((maxHorizSeg%mod)*(maxVertSeg%mod))%mod;
        long ans = (maxHorizSeg*maxVertSeg)%mod;

        return (int) ans;
    }
}