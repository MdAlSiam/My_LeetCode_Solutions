class Solution {
    bool isPossibleWithinDays(vector<int>& piles, int h, int mid) {
        long long int days = 0;
        for (int pile : piles) {
            days += (pile+mid-1)/mid;
        }
        return days <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for (int pile : piles) maxi = max(maxi, pile);

        int lo = 1;
        int hi = maxi;

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if (isPossibleWithinDays(piles, h, mid)) {
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        return lo;
    }
};