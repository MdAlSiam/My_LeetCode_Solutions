// LeetCode 1339: Maximum Product of Splitted Binary Tree

class Solution {
    int total = 0;
    long long int ans = 0;

    int dfs(TreeNode* curr) {
        if (curr == nullptr) return 0;
        int ansThisSubTree = dfs(curr->left)+dfs(curr->right)+curr->val;
        ans = max(ans, ansThisSubTree*(total-ansThisSubTree));
        return ansThisSubTree;
    }

public:
    int maxProduct(TreeNode* root) {
        total = dfs(root);   
        dfs(root);
        return ans%1000000007;
    }
};