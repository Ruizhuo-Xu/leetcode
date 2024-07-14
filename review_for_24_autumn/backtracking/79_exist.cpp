#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(board, visited, word, 1, i, j)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>> visited, string word, int idx, int x, int y) {
        if (idx == word.size()) {
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < dirs.size(); i++) {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
                continue;
            }
            if (!visited[newX][newY] && board[newX][newY] == word[idx]) {
                visited[newX][newY] = true;
                if (dfs(board, visited, word, idx + 1, newX, newY)) return true;
                visited[newX][newY] = false;
            }
        }
        return false;
    }
};