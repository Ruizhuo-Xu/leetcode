#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool backtracking(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int x, int y, int k) {
        // k表示当前要比较的字母位置
        if (board[x][y] != word[k]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }
        for (int i = 0; i < dir.size(); i++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if (nextX < 0 || nextX >= board.size() || nextY < 0 || nextY >= board[0].size()) {
                continue;
            }
            if (!visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                if (backtracking(board, word, visited, nextX, nextY, k + 1)) {
                    return true;
                }
                visited[nextX][nextY] = false; // 回溯
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = true;
                if (backtracking(board, word, visited, i, j, 0)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string str = "ABCCED";
    cout << Solution().exist(board, str) << endl;
    return 0;
}