class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.contains(endWord)) return 0;

        unordered_map<string, vector<string>> mp;
        int m = beginWord.size();

        for (const string& word : wordList) {
            for (int i = 0; i < m; i++) {
                string pattern = word;
                pattern[i] = '*';
                mp[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        // visited.insert(beginWord);

        while (!q.empty()) {
            auto [s, cnt] = q.front();
            q.pop();
            visited.insert(s);
            if (s == endWord) return cnt;

            for (int i = 0; i < m; ++i) {
                string pattern = s;
                pattern[i] = '*';
                for (const string& next : mp[pattern]) {
                    if (visited.contains(next)) continue;
                    else q.push({next, cnt + 1});
                }
            }
        }
        return 0;
    }
};
