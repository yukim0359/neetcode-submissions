class Solution {
public:
    vector<string> ans;
    string path;

    void dfs(int l, int r, int n) {
        if (l == n && r == n) {
            ans.push_back(path);
            return;
        }
        if (l < n) {
            path += '(';
            dfs(l + 1, r, n);
            path.pop_back();
        }
        if (r < l) {
            path += ')';
            dfs(l, r + 1, n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n);
        return ans;
    }
};
