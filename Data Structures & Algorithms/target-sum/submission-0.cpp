class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int s = -sum; s < sum; ++s) {
                if (dp[i][sum] != 0) {
                    dp[i + 1][sum + nums[i]] += dp[i][sum];
                    dp[i + 1][sum - nums[i]] += dp[i][sum];
                }
            }
        }

        return dp[n][target];
    }
};
