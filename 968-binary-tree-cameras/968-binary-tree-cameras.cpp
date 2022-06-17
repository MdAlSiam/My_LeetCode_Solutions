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
public:
    int minCameraCover(TreeNode* root) {
        int sum = 0;
        if (dfs(root, sum) == 0) sum++;
        return sum;
    }

    int dfs(TreeNode* curr, int& sum) {
        if (curr == nullptr) return 1;

        int left = dfs(curr->left, sum);
        int right = dfs(curr->right, sum);

        if (left == 0 or right == 0) {
            sum++;
            return 2;
        }

        if (left == 2 or right == 2) {
            return 1;
        }

        return 0;
    }
};