// Problem Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class Solution {
    map<int, bool> mp;
    int total;
    
    void init_map(int val) {
        mp.clear();
        total = val;
    }

    bool dfs(TreeNode* curr) {
        if (curr == nullptr) return false;
        int required = total-curr->val;
        if (mp.count(required)) return true;
        mp[curr->val] = true;
        return dfs(curr->left) or dfs(curr->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        init_map(k);
        return dfs(root);
    }
};