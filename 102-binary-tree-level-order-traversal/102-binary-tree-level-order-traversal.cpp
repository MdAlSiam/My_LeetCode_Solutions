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
    int nLevels = 0;

    void dfs(TreeNode* curr, int level) {
        nLevels = max(nLevels, level);
        if (curr->left) dfs(curr->left, level+1);
        if (curr->right) dfs(curr->right, level+1);
    }

    void dfs2(TreeNode* curr, int level, vector<vector<int>>& ans) {
        ans[level].push_back(curr->val);
        if (curr->left) dfs2(curr->left, level+1, ans);
        if (curr->right) dfs2(curr->right, level+1, ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        dfs(root, 0);
        for (int i = 0; i <= nLevels; i++) {
            vector<int> temp;
            ans.push_back(temp);
        }
        dfs2(root, 0, ans);
        return ans;
    }
};