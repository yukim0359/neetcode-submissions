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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur1 = list1, *cur2 = list2;
        ListNode *retRoot = new ListNode();
        ListNode *retCur = retRoot;

        while (cur1 || cur2) {
            if (!cur1) {
                retCur->next = cur2;
                retCur = cur2;
                cur2 = cur2->next;
            } else if (!cur2) {
                retCur->next = cur1;
                retCur = cur1;
                cur1 = cur1->next;
            } else {
                if (cur1->val <= cur2->val) {
                    retCur->next = cur1;
                    retCur = cur1;
                    cur1 = cur1->next;
                } else {
                    retCur->next = cur2;
                    retCur = cur2;
                    cur2 = cur2->next;
                }
            }
        }

        return retRoot->next;
    }
};
