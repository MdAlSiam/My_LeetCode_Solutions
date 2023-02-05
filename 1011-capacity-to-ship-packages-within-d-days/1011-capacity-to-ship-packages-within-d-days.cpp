class Solution {
    bool isPossible(vector<int>& weights, int days, int mid) {
        int allocatedDays = 0;
        int currTotal = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currTotal+weights[i] <= mid) {
                currTotal += weights[i];
            }
            else if (weights[i] <= mid) {
                allocatedDays++;
                currTotal = weights[i];
            }
            else {
                return false;
            }
        }
        allocatedDays++;

        return allocatedDays <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(), weights.end());

        int lo = INT_MAX;
        int hi = 0;

        for (int i = 0; i < weights.size(); i++) {
            lo = min(lo, weights[i]);
            hi += weights[i];
        }

        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;

            if (isPossible(weights, days, mid)) {
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }

        return lo;
    }
};