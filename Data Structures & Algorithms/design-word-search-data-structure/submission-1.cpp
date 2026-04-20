class WordDictionary {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;

        TrieNode() : isEnd(false) {}
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (!cur->children.contains(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    bool dfs(const string& word, int pos, TrieNode* node) {
        if (node == nullptr) return false;
        if (pos == word.size()) return node->isEnd;

        char c = word[pos];

        if (c == '.') {
            for (auto& [ch, nd] : node->children) {
                if (dfs(word, pos + 1, nd)) return true;
            }
            return false;
        } else {
            // if (!node->children.contains(c)) return false;
            return dfs(word, pos + 1, node->children[c]);
        }
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
