class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> state; 
    string order;

    bool dfs(char c) {
        if (state[c] == 1) return false;
        if (state[c] == 2) return true;

        state[c] = 1;

        for (char nei : adj[c]) {
            if (!dfs(nei)) return false;
        }

        state[c] = 2;
        order.push_back(c);
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        for (string& w : words) {
            for (char c : w) {
                adj[c]; 
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int minLen = min(w1.size(), w2.size());
            int j = 0;

            while (j < minLen && w1[j] == w2[j]) {
                j++;
            }

            // prefix invalid
            if (j == minLen) {
                if (w1.size() > w2.size()) return "";
                continue;
            }

            adj[w1[j]].insert(w2[j]);
        }

        for (auto& [c, _] : adj) {
            if (state[c] == 0) {
                if (!dfs(c)) return "";
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
