#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = 10000000;
        int ans;
        for (int i = 0; i < nums.size()-2; i++) {
            int lo = i+1;
            int hi = nums.size()-1;

            while (lo < hi) {
                int sum = nums[i]+nums[lo]+nums[hi];

                if (abs(target-sum) < minDiff) {
                    minDiff = abs(target-sum);
                    ans = sum;
                }

                if (sum < target) lo++;
                else hi--;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    // Call s
}