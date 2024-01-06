#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        int startRow = 0, endRow = h - 1;
        int startCol = 0, endCol = w - 1;
        vector<int> res;
        // 选择短边作为循环终止的条件
        int loop = min(h, w) / 2; // 每一轮循环边长-2
        while (loop--) {
            for (int i = startCol; i < endCol; i++) {
                res.push_back(matrix[startRow][i]);
            }
            for (int i = startRow; i < endRow; i++) {
                res.push_back(matrix[i][endCol]);
            }
            for (int i = endCol; i > startCol; i--) {
                res.push_back(matrix[endRow][i]);
            }
            for (int i = endRow; i > startRow; i--) {
                res.push_back(matrix[i][startCol]);
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        // 上面循环结束后可能有如下情况:  1.长宽都是偶数,则startRow(Col) > endRow(Col),无需其他处理
        // 2. 还剩下一行,此时startRow == endRow && startCol < endCol
        // 3. 还剩下一列,此时startCol == endCol && startRow < endRow
        // 4. 还剩下一个元素,此时startCol == endCol && startRow == endRow
        if (startCol == endCol && startRow == endRow) {
            res.push_back(matrix[startRow][startCol]);
        } else if (startRow == endRow && startCol < endCol) {
            for (int i = startCol; i <= endCol; i++) {
                res.push_back(matrix[startRow][i]);
            }
        } else if (startCol == endCol && startRow < endRow) {
            for (int i = startRow; i <= endRow; i++) {
                res.push_back(matrix[i][startCol]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = Solution().spiralOrder(matrix);
    for (int val : res) {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}