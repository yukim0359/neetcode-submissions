class Solution {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word;

        TrieNode() : word("") {}
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) {
            TrieNode* cur = root;
            for (char c : word) {
                if (!cur->children.contains(c)) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->word = word;
        }

        return root;
    }

    int rows, cols;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !node->children.contains(ch)) return;

        node = node->children[ch];
        if (node->word != "") {
            res.push_back(node->word);
            node->word = "";  // prevent duplication
        }

        board[r][c] = '#';
        if (r > 0)        dfs(board, r - 1, c, node, res);
        if (r + 1 < rows) dfs(board, r + 1, c, node, res);
        if (c > 0)        dfs(board, r, c - 1, node, res);
        if (c + 1 < cols) dfs(board, r, c + 1, node, res);
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> res;

        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, root, res);
            }
        }
        return res;
    }
};
