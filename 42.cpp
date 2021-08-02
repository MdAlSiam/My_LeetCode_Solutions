#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxFromLast(height.size());
        vector<int> maxFromFirst(height.size());

        for (int i = maxFromLast.size()-1; i >= 0; i--) {
            if (i == maxFromLast.size()-1) {
                maxFromLast[i] = height[i];
            }
            else {
                maxFromLast[i] = max(height[i], maxFromLast[i+1]);
            }
        }
        
        for (int i = 0; i < maxFromFirst.size(); i++) {
            if (i == 0) {
                maxFromFirst[i] = height[i];
            }
            else {
                maxFromFirst[i] =max(height[i], maxFromFirst[i-1]);
            }
        }

        bool positiveEncountered = false;

        int total = 0;
        int toTakeNow = 0;

        for (int i = 0; i < height.size(); i++) {
            if (height[i] > 0) positiveEncountered = true;
            if (not positiveEncountered) continue;

            if (i-1 >= 0 and i+1 < height.size()) {
                int lower = min(maxFromFirst[i-1], maxFromLast[i+1]);
                if (height[i] < lower) {
                    total += lower-height[i];
                }
            }
        }

        return total;
    }
};

int main() {
    // Problem Link: https://leetcode.com/problems/trapping-rain-water/
}