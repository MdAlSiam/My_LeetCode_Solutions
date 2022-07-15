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
    TreeNode helper(ref int[] preorder, ref int[] inorder, int preStart, int preStop, int inStart, int inStop) {
        if (inStart > inStop || preStart > preStop) return null;

        int rootVal = preorder[preStart];

        TreeNode root = new TreeNode(rootVal);

        int rootIndex = -1;
        for (int i = inStart; i <= inStop; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }

        int lInStart = inStart;
        int lInStop = rootIndex-1;
        int rInStart = rootIndex+1;
        int rInStop = inStop;

        int lPreStart = preStart+1;
        int lPreStop = lPreStart+lInStop-lInStart;
        int rPreStart = lPreStop+1;
        int rPreStop = preStop;

        root.left = helper(ref preorder, ref inorder, lPreStart, lPreStop, lInStart, lInStop);
        root.right = helper(ref preorder, ref inorder, rPreStart, rPreStop, rInStart, rInStop);

        return root;
    }
    
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        int inStart = 0;
        int inStop = inorder.Length-1;
        
        int preStart = 0;
        int preStop = preorder.Length-1;
        
        TreeNode ret = helper(ref preorder, ref inorder, preStart, preStop, inStart, inStop);
        
        return ret;
    }
}