class Solution {
public:
    int m, n;
    int ans;

    void dfs(int i, int j, int* area, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if (grid[i][j] == 0 || visited[i][j] == 1) return;
        visited[i][j] = 1;
        (*area)++;
        ans = max(ans, *area);

        if (i != 0) dfs(i - 1, j, area, grid, visited);
        if (i != m - 1) dfs(i + 1, j, area, grid, visited);
        if (j != 0) dfs(i, j - 1, area, grid, visited);
        if (j != n - 1) dfs(i, j + 1, area, grid, visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int area = 0;
                dfs(i, j, &area, grid, visited);
            }
        }

        return ans;
    }
};
