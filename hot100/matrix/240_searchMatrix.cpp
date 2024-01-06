#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 时间复杂度O(m + n),空间复杂度O(1)
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = n - 1; // 矩阵的右上角位置
        while (x < m && y >= 0) { // 不断更新右上角位置,缩小搜索矩阵的范围
            if (matrix[x][y] == target) { // 找到目标值
                return true;
            } else if (matrix[x][y] > target) { // 如果当前元素大于target,说明当前列剩余元素都是大于目标值,所以y--,舍弃当前列
                y--;
            } else { // 如果当前元素小于target,说明当前行剩余元素都是小于目标值,所以x++，舍弃当前行
                x++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    cout << Solution().searchMatrix(matrix, target) << endl;
    return 0;
}