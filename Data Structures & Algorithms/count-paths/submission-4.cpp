class Solution {
public:
    vector<vector<int>> comb_table = vector<vector<int>>(500, vector<int>(500, -1));

    int combination(int n, int k) {
        if (k == 0 || k == n) return 1;
        if (comb_table[n][k] != -1) return comb_table[n][k];
        return comb_table[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
    }

    int uniquePaths(int m, int n) {
        return combination((m - 1) + (n - 1), m - 1);
    }
};
