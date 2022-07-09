/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


public class Solution {
    bool dfs(TreeNode curr) {
        if (curr.val == 0 || curr.val == 1) {
            return curr.val == 0 ? false : true;
        }

        if (curr.val == 2) {
            return dfs(curr.left) || dfs(curr.right);
        }

        if (curr.val == 3) {
            return dfs(curr.left) && dfs(curr.right);
        }

        return true;
    }

    public bool EvaluateTree(TreeNode root) {
        return dfs(root);
    }
}