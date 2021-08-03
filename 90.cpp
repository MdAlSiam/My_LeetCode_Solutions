#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;

    bool* taken;

    void initTaken(int length) {
        taken = new bool[length];
        for (int i = 0; i < length; i++) {
            taken[i] = false;
        }
    }

    void go(vector<int>& nums, int position) {
        if (position >= nums.size()) {
            vector<int> an_ans;
            for (int i = 0; i < nums.size(); i++) {
                if (taken[i]) {
                    an_ans.push_back(nums[i]);
                }
            }
            ans.push_back(an_ans);

            return;
        }
        
        int curr_element = nums[position];
        int togo = position+1;

        for (int i = position; ; i++)  {
            if (i < nums.size() and nums[i] == curr_element) {

            }
            else {
                togo = i;
                break;
            }
        }

        go(nums, togo);
        for (int i = position; i < togo; i++) {
            taken[i] = true;
            go(nums, togo);
        }
        for (int i = position; i < togo; i++) {
            taken[i] = false;
        }  
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        initTaken(nums.size());
        sort(nums.begin(), nums.end());
        go(nums, 0);
        return ans;
    }
};

int main() {
    // Problem Link: https://leetcode.com/problems/subsets-ii/
}