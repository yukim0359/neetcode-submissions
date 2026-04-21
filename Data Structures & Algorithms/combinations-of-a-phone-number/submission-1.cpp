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
        if (digits == "") return {};
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        dfs(digits, 0);
        return ans;
    }
};
