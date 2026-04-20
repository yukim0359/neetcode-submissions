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
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode *cur1 = l1, *cur2 = l2, *curAns = ans;
        while (cur1 != nullptr || cur2 != nullptr || carry == 1) {
            int tmp = 0;
            if (cur1 != nullptr) tmp += cur1->val;
            if (cur2 != nullptr) tmp += cur2->val;
            if (carry == 1) tmp++;
            curAns->next = new ListNode(tmp % 10);
            carry = tmp / 10;
            if (cur1 != nullptr) cur1 = cur1->next;
            if (cur2 != nullptr) cur2 = cur2->next;
            curAns = curAns->next;
        }

        return ans->next;
    }
};
