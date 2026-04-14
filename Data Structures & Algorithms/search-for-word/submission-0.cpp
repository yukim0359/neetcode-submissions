class Solution {
public:
    int n;
    int m;
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int pos) {
        if (pos == word.size()) return true;
        if (board[i][j] != word[pos]) return false;
        if (i != 0 && dfs(i - 1, j, board, word, pos + 1)) {
            return true;
        }
        if (i != n - 1 && dfs(i + 1, j, board, word, pos + 1)) {
            return true;
        }
        if (j != 0 && dfs(i, j - 1, board, word, pos + 1)) {
            return true;
        }
        if (j != m - 1 && dfs(i, j + 1, board, word, pos + 1)) {
            return true;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

};
