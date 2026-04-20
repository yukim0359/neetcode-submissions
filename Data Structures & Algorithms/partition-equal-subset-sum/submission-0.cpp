class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int k: nums) {
            sum += k;
        }
        if (sum % 2 == 1) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= sum; ++s) {
                if (dp[i - 1][s]) {
                    dp[i][s] = true;
                    dp[i][s + nums[i - 1]] = true;
                    if ((s + nums[i - 1]) == sum / 2) return true;
                }
            }
        }
        return false;
    }
};
