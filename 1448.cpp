class Solution {
    int kount;

    void dfs(TreeNode* curr, int maxTillHere) {
        if (curr == nullptr) return;

        if (curr->val >= maxTillHere) {
            kount++;
            maxTillHere = curr->val;
        }

        dfs(curr->left, maxTillHere) ;
        dfs(curr->right, maxTillHere);
    }
public:
    int goodNodes(TreeNode* root) {
        kount = 0;
        dfs(root, -100000);
        return kount;
    }
};