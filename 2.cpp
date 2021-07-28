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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> digitsAtFirst;
        vector<int> digitsAtSecond;
        digitsAtFirst.clear();
        digitsAtSecond.clear();

        while (true) {
            digitsAtFirst.push_back(l1->val);
            if (l1->next == nullptr) break;
            l1 = l1->next;
        }

        while (true) {
            digitsAtSecond.push_back(l2->val);
            if (l2->next == nullptr) break;
            l2 = l2->next;
        }

        vector<int> final_digits;
        for (int i = 0; i < max(digitsAtFirst.size(), digitsAtSecond.size())+1; i++) {
            final_digits.push_back(0);
        }
        for (int i = 0; i < max(digitsAtFirst.size(), digitsAtSecond.size())+1; i++) {
            int d1, d2;
            d1 = d2 = 0;
            if (i < digitsAtFirst.size()) d1 = digitsAtFirst[i];
            if (i < digitsAtSecond.size()) d2 = digitsAtSecond[i];
            final_digits[i] += d1+d2;

            if (final_digits[i] >= 10) {
                final_digits[i+1] += final_digits[i]/10;
                final_digits[i] = final_digits[i]%10;
            }
        }

        reverse(final_digits.begin(), final_digits.end());
        
        int start;
        
        for (int i = 0; i < final_digits.size(); i++) {

            if (final_digits[i] != 0) {
                start = i;
                break;
            }
           
        }
        
        reverse(final_digits.begin()+start, final_digits.end());

        ListNode* curr = new ListNode();
        ListNode* ret = curr;

        bool got = false;

        for (int i = start; i < final_digits.size(); i++) {
            curr->val = final_digits[i];
            if (i != final_digits.size()-1) {
                curr->next = new ListNode();
                curr = curr->next;
            } 
           
        }

        return ret;
    }
};