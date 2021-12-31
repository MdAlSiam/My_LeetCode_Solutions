# Problem: https://leetcode.com/problems/reorder-list/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        # count the number of nodes
        curr = head
        nodeKount = 1

        while curr.next != None:
            curr = curr.next
            nodeKount += 1

        limit = int(nodeKount/2)

        # sorting the nodes in order it would appear in the final linked list
        firstNodeList = []
        secondNodeList = []

        curr = head
        currKount = 1
        if currKount <= limit:
            firstNodeList.append(curr)
        else:
            secondNodeList.append(curr)

        while curr.next != None:
            curr = curr.next
            currKount += 1
            if currKount <= limit:
                firstNodeList.append(curr)
            else:
                secondNodeList.append(curr)
        secondNodeList.reverse()

        # constructing the linked list from the prepared lists
        i = 0

        curr = ListNode()
        head = curr.next

        while i < len(firstNodeList) and i < len(secondNodeList):
            node1 = firstNodeList[i]
            node2 = secondNodeList[i]

            node2.next = None
            node1.next = node2
            curr.next = node1
            
            curr = curr.next
            curr = curr.next

            i += 1

        if i < len(firstNodeList):
            firstNodeList[i].next = None
            curr.next = firstNodeList[i]

        if i < len(secondNodeList):
            secondNodeList[i].next = None
            curr.next = secondNodeList[i]