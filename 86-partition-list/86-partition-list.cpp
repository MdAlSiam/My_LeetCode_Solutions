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
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans = nullptr;

        ListNode* curr = head;
        ListNode* anscurr = ans;

        for (int i = 0; i < 2; i++) {
            curr = head;

            while (curr != nullptr) {
                if (i == 0 && curr->val < x) {
                    if (ans == nullptr) {
                        ans = new ListNode(curr->val);
                        anscurr = ans;
                    }
                    else {
                        anscurr->next = new ListNode(curr->val);
                        anscurr = anscurr->next;
                    }
                }
                
                if (i == 1 && curr->val >= x) {
                    if (ans == nullptr) {
                        ans = new ListNode(curr->val);
                        anscurr = ans;
                    }
                    else {
                        anscurr->next = new ListNode(curr->val);
                        anscurr = anscurr->next;
                    }
                }

                curr = curr->next;
            }
        }
        
        return ans;
    }
};