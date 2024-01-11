#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtracking(n, 0, board);
        return res;
    }

    void backtracking(int n, int row, vector<string>& board) {
        if (row == n) {
            res.push_back(path);
            return ;
        }
        for (int col = 0; col < n; col++) {
            if (!isValid(board, col, row)) continue;
            board[row][col] = 'Q';
            path.push_back(board[row]);
            backtracking(n, row + 1, board);
            board[row][col] = '.';
            path.pop_back();
        }
    }

    bool isValid(vector<string>& board, int col, int row) {
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<string>> res = Solution().solveNQueens(4);
    for (auto strs : res) {
        for (auto str : strs) {
            cout << str << ' ';
        }
        cout << endl;
    }
    return 0;
}