class Solution {
public:
    vector<vector<int>> comb_table = vector<vector<int>>(500, vector<int>(500, -1));

    int combination(int n, int k) {
        if (k == 0 || k == n) return 1;
        if (comb_table[n - 1][k - 1] == -1) comb_table[n - 1][k - 1] = combination(n - 1, k - 1);
        if (comb_table[n - 1][k] == -1) comb_table[n - 1][k] = combination(n - 1, k);
        return comb_table[n - 1][k - 1] + comb_table[n - 1][k]; 
    }

    int uniquePaths(int m, int n) {
        return combination((m - 1) + (n - 1), m - 1);
    }
};
