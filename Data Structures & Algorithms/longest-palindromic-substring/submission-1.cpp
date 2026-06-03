class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        int start = 0, max_len = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < sz && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > max_len) {
                    max_len = len;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < sz; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }

        return s.substr(start, max_len);
    }
};
