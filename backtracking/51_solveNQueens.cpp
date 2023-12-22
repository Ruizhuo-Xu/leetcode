#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        // 棋盘的宽度就是for循环的长度，递归的深度就是棋盘的高度
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return res;
    }
    
    void backtracking(int n, int row, vector<string>& chessboard) {
        if (row == n) {
            res.push_back(chessboard);
            return ;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(chessboard, row, col, n)) {
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string>& chessboard, int row, int col, int n) {
        for (int i = row - 1; i >=0; i--) { // 判断同列是否存在Q
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) { // 判断斜向
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) { // 判断另一个斜向
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 4;
    vector<vector<string>> res = Solution().solveNQueens(n);
    for (vector<string> strs : res) {
        for (string s : strs) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}
