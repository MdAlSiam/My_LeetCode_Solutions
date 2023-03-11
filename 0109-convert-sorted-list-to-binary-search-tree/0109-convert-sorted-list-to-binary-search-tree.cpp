/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

class Solution {
    TreeNode* convertToBST(ListNode* start, ListNode* stop) {
        // base
        if (start == stop) return nullptr;

        // find mid (at slow)
        ListNode* slow = start;
        ListNode* fast = start;

        while (fast != stop and fast->next != stop) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // construct the BST
        TreeNode* head = new TreeNode(slow->val);
        head->left = convertToBST(start, slow);
        head->right = convertToBST(slow->next, stop);

        return head;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        return convertToBST(head, nullptr);
    }
};