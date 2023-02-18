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
    void dfs(TreeNode* root) {
        if (!root) return;
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        swap(root->left, root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* curr = root;
        dfs(curr);
        return root;
    }
};