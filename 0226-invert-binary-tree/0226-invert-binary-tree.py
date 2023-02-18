# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def dfs(curr):
            if (curr == None): return
            if (curr.left != None): dfs(curr.left)
            if (curr.right != None): dfs(curr.right)
            curr.left, curr.right = curr.right, curr.left

        dfs(root)
        return root
        