class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c: coins) {
                int paid_count = 1;
                while (i - paid_count * c >= 0) {
                    if (dp[i - paid_count * c] != INT_MAX) {
                        dp[i] = min(dp[i], dp[i - paid_count * c] + paid_count);
                    }
                    paid_count++;
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
