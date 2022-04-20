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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        LeftTraverse(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();

        if (top->right) {
            LeftTraverse(top->right);
        }

        return top->val;
    }
    
    bool hasNext() {
        if (not st.empty()) return true;
        return false;
    }

    void LeftTraverse(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
    }
};
