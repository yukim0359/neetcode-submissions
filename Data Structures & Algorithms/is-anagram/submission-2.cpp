class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;

        for (int i = 0; i < s.size(); ++i) {
            s_freq[s[i]]++;
        }
        for (int i = 0; i < t.size(); ++i) {
            t_freq[t[i]]++;
        }

        return s_freq == t_freq;
    }
};
