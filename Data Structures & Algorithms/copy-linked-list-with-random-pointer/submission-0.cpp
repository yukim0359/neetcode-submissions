/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* old_cur = head;
        Node* ans = new Node(head->val);
        mp[head] = ans;
        Node* new_cur = ans;

        while (old_cur != nullptr) {
            if (old_cur->next == nullptr) {
                new_cur->next = nullptr;
            } else if (!mp.contains(old_cur->next)) {
                new_cur->next = new Node(old_cur->next->val);
                mp[old_cur->next] = new_cur->next;
            } else {
                new_cur->next = mp[old_cur->next];
            }

            if (old_cur->random == nullptr) {
                new_cur->random = nullptr;
            } else if (!mp.contains(old_cur->random)) {
                new_cur->random = new Node(old_cur->random->val);
                mp[old_cur->random] = new_cur->random;
            } else {
                new_cur->random = mp[old_cur->random];
            }

            old_cur = old_cur->next;
            new_cur = new_cur->next;
        }

        return ans;
    }
};
