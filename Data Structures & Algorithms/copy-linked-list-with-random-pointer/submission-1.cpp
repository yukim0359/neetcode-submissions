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

        Node* cur = head;
        while (cur != nullptr) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        Node* old_cur = head;
        Node* ans = mp[head];
        Node* new_cur = ans;
        while (old_cur != nullptr) {
            new_cur->next = mp[old_cur->next];
            new_cur->random = mp[old_cur->random];
            old_cur = old_cur->next;
            new_cur = new_cur->next;
        }
        return ans;
    }
};
