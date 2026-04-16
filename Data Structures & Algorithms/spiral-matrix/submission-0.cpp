class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        vector<int> res;

        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) {
                res.push_back(matrix[top][c]);
            }
            top++;

            for (int r = top; r <= bottom; ++r) {
                res.push_back(matrix[r][right]);
            }
            right--;

            if (top <= bottom) {
                for (int c = right; c >= left; --c) {
                    res.push_back(matrix[bottom][c]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int r = bottom; r >= top; --r) {
                    res.push_back(matrix[r][left]);
                }
                left++;
            }
        }

        return res;

    }
};
