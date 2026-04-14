#include <array>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ret = true;
        // sub-box check
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                array<bool, 10> exists = {false};
                for (int ii=0; ii<3; ii++){
                    for (int jj=0; jj<3; jj++){
                        if (board[3 * i + ii][3 * j + jj] != '.') {
                            if (exists[int(board[3 * i + ii][3 * j + jj] - '0')]) ret = false;
                            else exists[int(board[3 * i + ii][3 * j + jj] - '0')] = true;
                        }
                    }
                }
            }
        }
        // row check
        for (int i=0; i<9; i++){
            array<bool, 10> exists = {false};
            for (int j=0; j<9; j++){
                if (board[i][j] != '.') {
                    if (exists[int(board[i][j] - '0')]) ret = false;
                    else exists[int(board[i][j] - '0')] = true;
                }
            }
        }
        // column check
        for (int j=0; j<9; j++){
            array<bool, 10> exists = {false};
            for (int i=0; i<9; i++){
                if (board[i][j] != '.') {
                    if (exists[int(board[i][j] - '0')]) ret = false;
                    else exists[int(board[i][j] - '0')] = true;
                }
            }
        }
        return ret;
    }
};
