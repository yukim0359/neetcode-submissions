class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i <= n - 1; ++i) {
            for (const string& w : wordDict) {
                if (dp[i] && i + w.size() <= n && s.substr(i, w.size()) == w) {
                    dp[i + w.size()] = true;
                }
            }
        }

        return dp[n];
    }
};
