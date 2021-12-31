class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def assistant(root):
            if not root: return 0
            ret = 0
            if root.val > high:
                ret += assistant(root.left)
            elif root.val < low:
                ret += assistant(root.right)
            else:
                ret += root.val
                ret += assistant(root.left)
                ret += assistant(root.right)
            return ret

        return assistant(root)