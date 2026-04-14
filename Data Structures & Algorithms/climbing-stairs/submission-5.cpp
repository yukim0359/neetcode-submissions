class Solution {
public:
    #define MAX_N 45
    int memo[MAX_N + 1];

    int solve(int n) {
        int ret;
        if (memo[n] != -1) return memo[n];
        if (n == 1) ret = 1;
        else if (n == 2) ret = 2;
        else ret = solve(n - 1) + solve(n - 2);
        if (memo[n] == -1) memo[n] = ret;
        return ret;
    }

    int climbStairs(int n) {
        for (int i = 0; i < MAX_N + 1; ++i) {
            memo[i] = -1;
        }
        return solve(n);
    }
};
