class Solution {
public:
    int rows, cols;
    // vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& vis) {
        if (vis[r][c]) return;
        vis[r][c] = true;
        if (r != 0) {
            if (heights[r - 1][c] >= heights[r][c]) dfs(heights, r - 1, c, vis);
        }
        if (r != rows - 1) {
            if (heights[r + 1][c] >= heights[r][c]) dfs(heights, r + 1, c, vis);
        }
        if (c != 0) {
            if (heights[r][c - 1] >= heights[r][c]) dfs(heights, r, c - 1, vis);
        }
        if (c != cols - 1) {
            if (heights[r][c + 1] >= heights[r][c]) dfs(heights, r, c + 1, vis);
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> vis_pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> vis_atl(rows, vector<bool>(cols, false));

        // pacific
        for (int i = 0; i < rows; ++i) {
            dfs(heights, i, 0, vis_pac);
        }
        for (int j = 0; j < cols; ++j) {
            dfs(heights, 0, j, vis_pac);
        }
        // atlantic
        for (int i = 0; i < rows; ++i) {
            dfs(heights, i, cols - 1, vis_atl);
        }
        for (int j = 0; j < cols; ++j) {
            dfs(heights, rows - 1, j, vis_atl);
        }

        vector<vector<int>> ret;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (vis_pac[i][j] && vis_atl[i][j]) ret.push_back({i, j});
            }
        }
        return ret;
    }
};
