class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void insert(Node* node) {
        Node* p = right->prev;
        p->next = node;
        node->prev = p;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(-1, -1);
        right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (!mp.contains(key)) return -1;
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);

        if ((int)mp.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
