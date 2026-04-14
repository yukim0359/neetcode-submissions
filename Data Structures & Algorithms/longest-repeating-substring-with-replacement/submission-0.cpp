class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int l = 0;
        int max_freq = 0;
        int ret = 0;
        for (int r = 0; r < s.size(); r++) {
            cnt[s[r] - 'A']++;
            max_freq = max(max_freq, cnt[s[r] - 'A']);

            while ((r - l + 1) - max_freq > k) {
                cnt[s[l] - 'A']--;
                l++;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
