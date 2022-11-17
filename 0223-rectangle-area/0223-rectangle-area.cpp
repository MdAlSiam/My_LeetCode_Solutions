class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if (ax2 <= bx1 or bx2 <= ax1 or ay2 <= by1 or by2 <= ay1) {
            // No intersection
            return abs(ax1-ax2)*abs(ay1-ay2) + abs(bx1-bx2)*abs(by1-by2);
        }
        else {
            // Has intersection
            int xs[4] = {ax1, ax2, bx1, bx2};
            int ys[4] = {ay1, ay2, by1, by2};
            sort(xs, xs+4);
            sort(ys, ys+4);

            return abs(ax1-ax2)*abs(ay1-ay2) + abs(bx1-bx2)*abs(by1-by2) - (xs[2]-xs[1])*(ys[2]-ys[1]);
        }
    }
};