class Solution {
    map<TreeNode*, int> mp;

    int go(TreeNode* curr) {
        if (curr == nullptr) return 0;

        if (mp.count(curr)) return mp[curr];

        int ret1 = 0;
        int ret2 = 0;

        int lsl = 0, lsr = 0;
        int rsl = 0, rsr = 0;

        if (curr->left and curr->left->left) lsl = go(curr->left->left);
        if (curr->left and curr->left->right) lsr = go(curr->left->right);
        if (curr->right and curr->right->left) rsl = go(curr->right->left);
        if (curr->right and curr->right->right) rsr = go(curr->right->right);

        ret1 += curr->val + lsl + lsr + rsl + rsr;  

        ret2 += go(curr->left) + go(curr->right);   

        return mp[curr] = max(ret1, ret2);
    }
public:
    int rob(TreeNode* root) {
        mp.clear();
        return go(root);
    }
};