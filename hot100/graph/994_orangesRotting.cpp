#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> que;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push(pair<int, int>(i, j));
                } else if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        if (cnt == 0) return 0;
        int res = 0;
        while (!que.empty()) {
            int size = que.size();
            res++;
            while (size--) {
                pair<int, int> coord = que.front();
                que.pop();
                for (int i = 0; i < dir.size(); i++) {
                    int nextX = coord.first + dir[i][0];
                    int nextY = coord.second + dir[i][1];
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (grid[nextX][nextY] == 1) { // == 1说明该橘子还未被遍历到
                        grid[nextX][nextY] = 2; // 腐烂
                        cnt--; // 还未腐烂的橘子的数量
                        que.push(pair<int, int>(nextX, nextY));
                    }
                }
            }
            if (cnt == 0) {
                break;
            }
        }
        return cnt > 0 ? -1 : res;
    }
};

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << Solution().orangesRotting(grid) << endl;
    return 0;
}