#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums.size(); i++) {
            pairs.push_back({nums[i], i});
        }

        // n log n
        sort(pairs.begin(), pairs.end());

        int lp = 0;
        int rp = pairs.size()-1;

        vector<int> ans;
        ans.clear();

        // n/2
        while (lp < rp) {
            int sum = pairs[lp].first+pairs[rp].first;
            if (sum == target) {
                ans.push_back(pairs[lp].second);
                ans.push_back(pairs[rp].second);
                break;
            }
            
            if (sum < target) {
                lp++; 
            }
            else {
                rp--;
            }
        }

        return ans;
    }
};

int main() {
    // Problem Link: https://leetcode.com/problems/two-sum/
    // Complexity: O(n log n) + O(n) = O(n long n)
}