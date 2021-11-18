#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Accepted
    // 41. First Missing Positive
    // https://leetcode.com/problems/first-missing-positive/
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(INT_MIN);
        nums.push_back(INT_MAX);
        
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            long long int gapStartedAt = (long long int) nums[i-1]+1;
            long long int gapStoppedAt = (long long int) nums[i]-1;

            if (gapStartedAt <= gapStoppedAt) {
                if (gapStartedAt <= 0 and gapStoppedAt >= 1) {
                    return 1;
                }
                else if (gapStartedAt >= 1) {
                    return (int) gapStartedAt;
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution s;
} 