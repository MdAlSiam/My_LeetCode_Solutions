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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;

        int kount = 0;

        while (curr != nullptr) {
            kount++;
            curr = curr->next;
        }

        kount -= n;

        if (kount == 0) {
            return head->next;
        }

        curr = head;
        kount--;
        while (kount--) curr = curr->next;

        curr->next = curr->next->next;
        
        return head;
    }
};