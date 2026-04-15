class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;
            for (int j = 0; j <= nums[i]; ++j) {
                if (i + j < n) dp[i + j] = true;
            }
        }
        return dp[n - 1];
    }
};
