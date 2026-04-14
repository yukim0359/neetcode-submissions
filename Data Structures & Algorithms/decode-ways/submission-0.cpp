class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        if (n == 1) return 1;
        int dp[n];
        dp[0] = 1;
        dp[-1] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i] = dp[i - 2];
                } else {
                    return 0;
                }
            }
            else if (s[i] - '0' >= 1 && s[i] - '0' <= 6) {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
                }
            }
            else {
                if (s[i - 1] == '1') {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[n - 1];
    }
};
