#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0, 0);
    }

    bool backtracking(vector<vector<char>>& board, int row, int col) {
        for (int i = row; i < board.size(); i++) {
            for (int j = col; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char c = '1'; c <= '9'; c++) {
                    if (check(board, i, j, c)) {
                        board[i][j] = c;
                        if (backtracking(board, i, j)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] != '.' && board[i][col] == c) {
                return false;
            }
        }
        for (int i = 0; i < board[0].size(); i++) {
            if (board[row][i] != '.' && board[row][i] == c) {
                return false;
            }
        }
        int idx1 = row / 3;
        int idx2 = col / 3;
        for (int i = idx1 * 3; i < idx1 * 3 + 3; i++) {
            for (int j = idx2 * 3; j < idx2 * 3 + 3; j++) {
                if (board[i][j] != '.' && board[i][j] == c) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution().solveSudoku(board);
    for (vector<char> row : board) {
        for (char s : row) {
            cout << s << ' ';
        }
        cout << endl;
    }
    return 0;
}