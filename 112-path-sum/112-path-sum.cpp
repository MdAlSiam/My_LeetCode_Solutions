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
    int target;

    bool dfs(TreeNode* curr, int sum) {
        if (curr == nullptr) {
            return false;
        }
        
        if (curr->left == nullptr and curr->right == nullptr) {
            if (target == sum+curr->val) return true;
            return false;
        }

        bool ret1, ret2;
        
        ret1 = ret2 = false;
        
        ret1 = dfs(curr->left, sum+curr->val);

        ret2 = dfs(curr->right, sum+curr->val);

        return ret1 | ret2;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        if (root == nullptr) return false;
        return dfs(root, 0);
    }
};