/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans = nullptr;

    void go(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return;
        }
        
        if (cloned->val == target->val) {
            ans = cloned;
            return;
        }

        go(original->left, cloned->left, target);
        go(original->right, cloned->right, target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        go(original, cloned, target);
        return ans;
    }
};