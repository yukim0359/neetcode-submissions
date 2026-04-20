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
    int countNodes(ListNode* head) {
        ListNode* cur = head;
        int ret = 0;
        while (cur != nullptr) {
            cur = cur->next;
            ret++;
        }
        return ret;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num_nodes = countNodes(head);
        ListNode* prev = nullptr;
        ListNode* cur = head;

        if (num_nodes == n) return head->next;

        for (int i = 0; i < num_nodes - n; ++i) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;

        return head;
    }
};
