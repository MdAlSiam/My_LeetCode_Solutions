class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
            [] (const auto &a, const auto &b) {
                return a[1] > b[1];
            }
        );

        int ans = 0;

        for (vector<int> v : boxTypes) {
            int toTake = min(truckSize, v[0]);

            truckSize -= toTake;

            ans += toTake*v[1];

            if (!toTake) break;
        }

        return ans;
    }
};