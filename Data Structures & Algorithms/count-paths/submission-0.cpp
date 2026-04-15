class Solution {
public:
    int combination(int n, int k) {
        if (k == 0 || k == n) return 1;
        return combination(n - 1, k - 1) + combination(n - 1, k); 
    }

    int uniquePaths(int m, int n) {
        return combination((m - 1) + (n - 1), m - 1);
    }
};
