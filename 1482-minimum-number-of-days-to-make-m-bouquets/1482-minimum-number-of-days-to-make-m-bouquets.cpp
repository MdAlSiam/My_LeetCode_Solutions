class Solution {
    int mini = INT_MAX;
    int maxi = 0;
    
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
        int consecutive = 0;
        int made = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consecutive++;
                
                if (consecutive == k) {
                    made++;
                    consecutive = 0;
                }
            }
            else {
                consecutive = 0;
            }
        }
        
        return made >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        
        int lo = mini;
        int hi = maxi;
        
        bool possible = false;
        
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            if (isPossible(bloomDay, m, k, mid)) {
                hi = mid-1;
                possible = true;
            }
            else {
                lo = mid + 1;
            }
        }
        
        if (!possible) return -1;
        return lo;
    }
};