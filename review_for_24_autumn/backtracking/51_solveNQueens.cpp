#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        backtracking(n, board, res, 0);
        return res;
    }

    void backtracking(int n, vector<string>& board, vector<vector<string>>& res, int row) {
        if (row == n) {
            res.push_back(board);
            return ;
        }
        for (int col = 0; col < board[row].size(); col++) {
            if (check(board, row, col)) {
                board[row][col] = 'Q';
                backtracking(n, board, res, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool check(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board[0].size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<string>> res = Solution().solveNQueens(4);
    for (vector<string> strs : res) {
        for (string s : strs) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}