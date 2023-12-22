#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       backtracking(board);
    }

    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) { // 遍历行
            for (int j = 0; j < board[0].size(); j++) { // 遍历列
                if (board[i][j] != '.') {
                    continue;
                }
                for (char k = '1'; k <= '9'; k++) {
                    if (isValid(board, i, j, k)) {
                        board[i][j] = k;
                        if (backtracking(board)) return true;;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < board[0].size(); i++) { // 行
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int i = 0; i < board.size(); i++) { // 列
            if (board[i][col] == val) {
                return false;
            }
        }
        int rowStart = (row / 3) * 3;
        int colStart = (col / 3) * 3;
        for (int i = rowStart; i < rowStart + 3; i++) {
            for (int j = colStart; j < colStart + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}};
    Solution().solveSudoku(board);
    for (auto it : board) {
        for (char c : it) {
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0;
}