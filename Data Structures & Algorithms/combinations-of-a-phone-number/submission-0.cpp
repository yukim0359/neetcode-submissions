class Solution {
public:
    vector<string> ans;
    string path;
    unordered_map<char, unordered_set<char>> mp;

    void dfs(string digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (int x : mp[digits[idx]]) {
            path.push_back(x);
            dfs(digits, idx + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[4] = {'g', 'h', 'i'};
        mp[4] = {'g', 'h', 'i'};
        dfs(digits, 0);
        return ans;
    }
};
