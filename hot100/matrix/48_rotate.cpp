#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // matrix中每个元素顺时针旋转90°: matrix[row][col] -> matrix[col][n - row - 1]
        int n = matrix.size();
        int loop = n / 2;
        int startCol = 0;
        int endCol = n - 1;
        int row = 0;
        while (loop--) {
            for (int i = startCol; i < endCol; i++) {
                // 完成矩阵外层元素的一次旋转
                int temp = matrix[i][n - row - 1];
                matrix[i][n - row - 1] = matrix[row][i]; // matrix[row][i]旋转90
                swap(matrix[n - row - 1][n - i - 1], temp); // matrix[i][n - row - 1]旋转90
                swap(matrix[n - i - 1][row], temp); // matrix[n - row - 1][n - i - 1]旋转90
                matrix[row][i] = temp; // matrix[n - i - 1][row]旋转90
            }
            // 矩阵边界收缩
            startCol++;
            endCol--;
            row++;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution().rotate(matrix);
    for (vector<int> row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}