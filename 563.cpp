class Solution {
    int ans = 0;

    int go(TreeNode* curr) {
        if (curr == nullptr) return 0;

        int left = go(curr->left);
        int right = go(curr->right);

        ans += abs(left-right);

        return curr->val+left+right;
    }
public:
    int findTilt(TreeNode* root) {
        int _ = go(root);
        return ans;
    }
};