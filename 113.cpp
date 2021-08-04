#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {     
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<vector<int>> ans;
    int target;

    void dfs(TreeNode* curr, int curr_sum, vector<int> a_path) {
        if (curr == nullptr) return;

        a_path.push_back(curr->val);
        curr_sum += curr->val;

        if (curr->left == nullptr and curr->right == nullptr and curr_sum == target) {
            ans.push_back(a_path);
            a_path.pop_back();
            return;
        }

        dfs(curr->left, curr_sum, a_path);
        dfs(curr->right, curr_sum, a_path);

        a_path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        vector<int> a_path;
        dfs(root, 0, a_path);

        return ans;
    }
};

int main() {
    // Link to the problem: https://leetcode.com/problems/path-sum-ii/
}