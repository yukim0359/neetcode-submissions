class Solution {
public:
    int m, n;

    pair<int, int> gridIndex(int idx) {
        return {idx / n, idx % n};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int row = gridIndex(mid).first;
            int col = gridIndex(mid).second;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
