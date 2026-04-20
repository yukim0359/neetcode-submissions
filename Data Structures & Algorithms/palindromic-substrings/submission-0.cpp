class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                ans++;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }

        return ans;
    }
};
