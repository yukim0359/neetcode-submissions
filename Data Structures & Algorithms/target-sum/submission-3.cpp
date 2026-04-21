class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int s = -sum; s <= sum; ++s) {
                if (dp[i].contains(s)) {
                    dp[i + 1][s + nums[i]] += dp[i][s];
                    dp[i + 1][s - nums[i]] += dp[i][s];
                    cout << i << " " << s << endl;
                }
            }
        }

        return dp[n][target];
    }
};
