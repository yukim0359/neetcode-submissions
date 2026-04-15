class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->children.contains(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->children.contains(c)) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c: prefix) {
            if (!cur->children.contains(c)) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
