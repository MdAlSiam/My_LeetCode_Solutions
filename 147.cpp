
class Solution {
    void insert(ListNode* head, ListNode* node) {
        while (head->next and head->next->val < node->val) head = head->next;

        node->next = head->next;
        head->next = node;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted_list_head = new ListNode();

        while (head) {
            ListNode* temp = head->next;

            insert(sorted_list_head, head);

            head = temp;
        }

        return sorted_list_head->next;
    }
}; 