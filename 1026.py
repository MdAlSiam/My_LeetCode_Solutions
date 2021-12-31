from typing_extensions import Self

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.ans = 0

    def go(self, curr, maxVal, minVal):
        self.ans = max(self.ans, abs(maxVal-minVal))

        if curr.left is not None:
            newMax = max(maxVal, curr.left.val)
            newMin = min(minVal, curr.left.val)

            self.go(curr.left, newMax, newMin)

        if curr.right is not None:
            newMax = max(maxVal, curr.right.val)
            newMin = min(minVal, curr.right.val)

            self.go(curr.right, newMax, newMin)

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.go(root, root.val, root.val)
        return self.ans