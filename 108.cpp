#include <bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    TreeNode* go(vector<int>& nums, int start, int stop) {
        if (start > stop) {
            return nullptr;
        }

        int mid = start + (stop - start) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = go(nums, start, mid-1);
        node->right = go(nums, mid+1, stop);
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return go(nums, 0, nums.size()-1);
    }
};

int main() {
    Solution s;
    // Call s
}