class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ret = 0;
        int l = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (mp.contains(c)) {
                l = max(l, mp[c] + 1);
            }
            mp[c] = i;
            ret = max(ret, i - l + 1);
        }
        return ret;
    }
};
