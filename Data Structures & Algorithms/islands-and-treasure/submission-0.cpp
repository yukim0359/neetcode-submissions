class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i != 0 && grid[i - 1][j] == INT_MAX) {
                q.push({i - 1, j});
                grid[i - 1][j] = grid[i][j] + 1;
            }
            if (i != m - 1 && grid[i + 1][j] == INT_MAX) {
                q.push({i + 1, j});
                grid[i + 1][j] = grid[i][j] + 1;
            }
            if (j != 0 && grid[i][j - 1] == INT_MAX) {
                q.push({i, j - 1});
                grid[i][j - 1] = grid[i][j] + 1;
            }
            if (j != n - 1 && grid[i][j + 1] == INT_MAX) {
                q.push({i, j + 1});
                grid[i][j + 1] = grid[i][j] + 1;
            }
        }
    }
};
