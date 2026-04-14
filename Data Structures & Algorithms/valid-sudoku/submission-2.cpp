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
                            if (exists[char_to_int(board[3 * i + ii][3 * j + jj])]) ret = false;
                            else exists[char_to_int(board[3 * i + ii][3 * j + jj])] = true;
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
                    if (exists[char_to_int(board[i][j])]) ret = false;
                    else exists[char_to_int(board[i][j])] = true;
                }
            }
        }
        // column check
        for (int j=0; j<9; j++){
            array<bool, 10> exists = {false};
            for (int i=0; i<9; i++){
                if (board[i][j] != '.') {
                    if (exists[char_to_int(board[i][j])]) ret = false;
                    else exists[char_to_int(board[i][j])] = true;
                }
            }
        }
        return ret;
    }
private:
    int char_to_int(char ch) {
        return int(ch - '0');
    }
};
