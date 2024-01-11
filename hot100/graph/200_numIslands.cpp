#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int res = 0;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < dir.size(); i++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) { // 边界判断
                continue;
            }
            if (!visited[nextX][nextY] && grid[nextX][nextY] == '1') { // 4个方向搜寻相连的陆地
                // visited[nextX][nextY] = true; // 标记访问
                dfs(grid, visited, nextX, nextY);
            }
        }
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        queue<pair<int, int>> que;
        que.push(pair<int, int>(x, y));
        while (!que.empty()) {
            pair<int, int> coord = que.front();
            que.pop();
            for (int i = 0; i < dir.size(); i++) {
                int nextX = coord.first + dir[i][0];
                int nextY = coord.second + dir[i][1];
                if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
                if (!visited[nextX][nextY] && grid[nextX][nextY] == '1') {
                    que.push(pair<int, int>(nextX, nextY));
                    visited[nextX][nextY] = true; // push进去之后马上赋值
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') { // 如果当前节点还未被遍历过，且是陆地,则标记为岛屿，并搜索相连的陆地
                    res++;
                    // visited[i][j] = true;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<char>> grid = {{'1','1','1','1','0'}, {'1','1','0','1','0'},
        {'1','1','0','0','0'}, {'0','0','0','0','0'}};
    cout << Solution().numIslands(grid) << endl;
    return 0;
}