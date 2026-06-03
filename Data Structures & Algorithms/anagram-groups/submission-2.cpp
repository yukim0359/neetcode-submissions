class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            anagram_mp[key].push_back(s);
        }

        vector<vector<string>> group_anagram;
        for (auto& [key, group] : anagram_mp) {
            group_anagram.push_back(group);
        }

        return group_anagram;
    }
};
