class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diffs;

        for (int i = 0; i < rocks.size(); i++) {
            diffs.push_back(capacity[i]-rocks[i]);
        }

        sort(diffs.begin(), diffs.end());

        int ans = 0;

        for (int diff : diffs) {
            if (diff <= additionalRocks) {
                ans++;
                additionalRocks -= diff;
            }
            else {
                break;
            }
        }

        return ans;
    }
};