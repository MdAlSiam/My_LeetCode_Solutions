class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int kount = 0;
        ListNode* curr = head;

        while (curr) {
            kount++;
            curr = curr->next;
        }

        int firstIndex = k;
        int lastIndex = kount-k+1;

        // 1 2 3 4 5 6 7
        // 2 6
        // 7-2+1 = 6

        ListNode* curr1 = head;
        ListNode* curr2 = head;

        int kaka = 0;

        while (curr1) {
            kaka++;
            if (kaka == firstIndex) {
                break;
            }
            curr1 = curr1->next;
        }

        kaka = 0;

        while (curr2) {
            kaka++;
            if (kaka == lastIndex) {
                break;
            }
            curr2 = curr2->next;
        }

        swap(curr1->val, curr2->val);

        return head;
    }
};