class Solution {
    struct myNode {
        TreeNode* node;
        int sumHere;
    };

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        myNode aNode;
        aNode.node = root;
        aNode.sumHere = root->val;

        queue<myNode> q;
        q.push(aNode);

        while (!q.empty()) {
            myNode curr = q.front();
            q.pop();

            if (curr.sumHere == targetSum and curr.node->left == nullptr and curr.node->right == nullptr) {
                return true;
            }

            if (curr.node->left) {
                aNode.node = curr.node->left;
                aNode.sumHere = curr.sumHere + curr.node->left->val;
                q.push(aNode);
            }

            if (curr.node->right) {
                aNode.node = curr.node->right;
                aNode.sumHere = curr.sumHere + curr.node->right->val;
                q.push(aNode);
            }
        }

        return false;
    }
};