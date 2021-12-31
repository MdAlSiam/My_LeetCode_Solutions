class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> bits;

        ListNode* curr = head;

        while (curr) {
            bits.push_back(curr->val);
            curr = curr->next;
        }

        int ans = 0;

        int toAdd = 1;

        for (int i = bits.size()-1; i >= 0; i--) {
            ans += bits[i]*toAdd;
            toAdd *= 2;
        }
        
        return ans;
    }
};