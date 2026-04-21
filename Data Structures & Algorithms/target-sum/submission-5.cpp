class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (auto [s, cnt] : dp[i]) {
                dp[i + 1][s + nums[i]] += cnt;
                dp[i + 1][s - nums[i]] += cnt;
            }
        }

        return dp[n][target];
    }
};
