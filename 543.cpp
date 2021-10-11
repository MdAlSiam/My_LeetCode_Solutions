class Solution {
    int diameter = 0;
    int dfs(TreeNode* curr) {
        if (curr == nullptr) return 0;
        int leftDepth = dfs(curr->left);
        int rightDepth = dfs(curr->right);
        diameter = max(diameter, leftDepth+rightDepth);
        return 1+max(leftDepth, rightDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};