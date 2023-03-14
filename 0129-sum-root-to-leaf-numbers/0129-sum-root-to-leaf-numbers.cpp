//  Definition for a binary tree node.
/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
 
class Solution {
    int sum;
    void calculate(TreeNode* curr, int numTillNow) {
        numTillNow = 10*numTillNow+curr->val;
        if (curr->left == nullptr and curr->right == nullptr) {
            sum += numTillNow;
            return;
        }
        if (curr->left != nullptr) calculate(curr->left, numTillNow);
        if (curr->right != nullptr) calculate(curr->right, numTillNow);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        calculate(root, 0);
        return sum;
    }
};