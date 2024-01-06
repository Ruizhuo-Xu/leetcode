#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 使用两个数组分别记录需要置零的行和列
        // 时间复杂度O(mn),空间复杂度O(m+n)
        vector<bool> rows(matrix.size(), false);
        vector<bool> cols(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution().setZeroes(matrix);
    for (vector<int> row : matrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}