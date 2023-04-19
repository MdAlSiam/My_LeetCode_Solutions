# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        def dfs(curr, left, right):
            if not curr:
                return max(0, left-1, right-1)
            ans = max(left, right)
            if left: 
                ans = max(ans, dfs(curr.left, 1, 0))
                ans = max(ans, dfs(curr.right, 0, left+1))
            elif right:
                ans = max(ans, dfs(curr.left, right+1, 0))
                ans = max(ans, dfs(curr.right, 0, 1))
            return ans
        
        return max(dfs(root.left, 1, 0), dfs(root.right, 0, 1))