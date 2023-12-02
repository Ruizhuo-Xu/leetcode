#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int h = rows;
        int w = cols;
        int cnt = 0;
        int row = 0;
        int col = 0;
        vector<int> res(rows*cols);
        while (h > 1 && w > 1) {
            for (int i = 0; i < w - 1; i++) {
                res[cnt++] = matrix[row][col++];
            }
            for (int i = 0; i < h - 1; i++) {
                res[cnt++] = matrix[row++][col];
            }
            for (int i = 0; i < w - 1; i++) {
                res[cnt++] = matrix[row][col--];
            }
            for (int i = 0; i < h - 1; i++) {
                res[cnt++] = matrix[row--][col];
            }
            row++, col++;
            h -= 2, w -= 2;
        }
        if (h == 1) {
            for (int i = 0; i < w; i++) {
                res[cnt++] = matrix[row][col++];
            }
        } else if (w == 1) {
            for (int i = 0; i < h; i ++) {
                res[cnt++] = matrix[row++][col];
            }
        }
        return res;
    }
};

int main() {
    Solution so = Solution();
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> matrix = {{{1,2,3,4},{5,6,7,8},{9,10,11,12}}};
    vector<vector<int>> matrix = {{{7},{9},{6}}};
    vector<int> res = so.spiralOrder(matrix);
    for (auto it : res) {
        cout << it << ' ';
    }
    return 0;
}