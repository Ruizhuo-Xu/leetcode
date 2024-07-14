#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        queue<pair<int, int>> que;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                } else if (grid[i][j] == 2) {
                    que.push(pair<int, int>(i, j));
                }
            }
        }
        int res = 0;
        while (!que.empty()) {
            if (cnt == 0) {
                break;
            }
            int size = que.size();
            res++;
            while(size--) {
                pair<int, int> coor = que.front();
                que.pop();
                for (int i = 0; i < dirs.size(); i++) {
                    int newX = coor.first + dirs[i][0];
                    int newY = coor.second + dirs[i][1];
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
                    if (grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        cnt--;
                        que.push(pair<int, int>(newX, newY));
                    }
                }
            }
        }
        return cnt > 0 ? -1 : res;
    }
};