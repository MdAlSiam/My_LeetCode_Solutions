/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool ans = true;

    pair<int, int> validate(TreeNode* curr) {
        if (curr->left == nullptr and curr->right == nullptr) {
            return {curr->val, curr->val};
        }

        long long int leftMin = 1 << 31;
        long long int leftMax = -leftMin+1;

        long long int rightMin = 1 << 31;
        long long int rightMax = -rightMin+1; 

        if (curr->left) {
            pair<int, int> leftVals = validate(curr->left);

            leftMin = leftVals.first;
            leftMax = leftVals.second;

            if (leftMax < curr->val);
            else {ans = false; return {0, 0};}
        }

        if (curr->right) {
            pair<int, int> rightVals = validate(curr->right);

            rightMin = rightVals.first;
            rightMax = rightVals.second;

            if (rightMin > curr->val);
            else {ans = false; return {0, 0};}
        }

        if (curr->left and curr->right) return {min((int)leftMin, curr->val), max((int)rightMax, curr->val)};
        else if (curr->left) return {min((int)leftMin, curr->val), max((int)leftMax, curr->val)};
        else if (curr->right) return {min((int)rightMin, curr->val), max((int)rightMax, curr->val)};
        return {0, 0}; // Won't ever hit
    }
public:
    bool isValidBST(TreeNode* root) {
        ans = true;
        validate(root);
        return ans;
    }
};