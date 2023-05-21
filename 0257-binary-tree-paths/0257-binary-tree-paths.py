# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []

        def dfs(curr, path):
            if len(path): path = f'{path}->{curr.val}'
            else: path = f'{curr.val}'
                
            if (curr.left is None and curr.right is None):
                ans.append(path)
                return
                
            if (curr.left): dfs(curr.left, path)
            if (curr.right): dfs(curr.right, path)


        dfs(root, "")
        return ans
        