#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int fmax[n];
        int bmin[n];
        
        fmax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > fmax[i-1]) fmax[i] = nums[i];
            else fmax[i] = fmax[i-1];
        }
        
        bmin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < bmin[i+1]) bmin[i] = nums[i];
            else bmin[i] = bmin[i+1];
        }
        
        int ans;
        
        for (int i = 0; i < n-1; i++) {
            if (fmax[i] <= bmin[i+1]) {
                ans = i+1;
                break;
            }
        }
        
        return ans;
    }
};

int main() {
    // Call whatever it requries or run here: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
}