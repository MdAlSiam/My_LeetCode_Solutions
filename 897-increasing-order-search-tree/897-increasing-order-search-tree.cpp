class Solution {
    vector<int> vals;

    void dfs(TreeNode* curr) {
        if (curr == nullptr) return;

        vals.push_back(curr->val);

        dfs(curr->left);
        dfs(curr->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);

        sort(vals.begin(), vals.end());

        TreeNode* new_root = new TreeNode(vals[0]);
        TreeNode* prev = new_root;

        for (int i = 1; i < vals.size(); i++) {
            TreeNode* new_node = new TreeNode(vals[i]);
            prev->right = new_node;
            prev = new_node;
        }

        return new_root;
    }
};