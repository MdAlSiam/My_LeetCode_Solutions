class Solution {
    vector<int> ans;

    void dfs(TreeNode* curr, int level) {
        if (level == ans.size()) {
            ans.push_back(curr->val);
        }

        if (curr->right) dfs(curr->right, level+1);
        if (curr->left) dfs(curr->left, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return ans;
        dfs(root, 0);
        return ans;
    }
};