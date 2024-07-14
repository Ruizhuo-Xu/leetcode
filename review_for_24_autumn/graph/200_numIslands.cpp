#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res += 1;
                    visited[i][j] = true;
                    // dfs(grid, visited, i, j);
                    bfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < dirs.size(); i++) {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            if (newX < 0 || newX >= m || newY < 0 || newY >= n) {
                continue;
            }
            if (!visited[newX][newY] && grid[newX][newY] == '1') {
                visited[newX][newY] = true;
                dfs(grid, visited, newX, newY);
            }
        }
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> que;
        que.push({x, y});
        while (!que.empty()) {
            pair<int, int> coor = que.front();
            que.pop();
            for (int i = 0; i < dirs.size(); i++) {
                int newX = coor.first + dirs[i][0];
                int newY = coor.second + dirs[i][1];
                if (newX < 0 || newX >= m || newY < 0 || newY >=n) continue;
                if (!visited[newX][newY] && grid[newX][newY] == '1') {
                    visited[newX][newY] = true;
                    que.push({newX, newY});
                }
            }
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;  // 输入m行n列
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >>  grid[i][j];
        }
    }
    cout << Solution().numIslands(grid) << endl;
}