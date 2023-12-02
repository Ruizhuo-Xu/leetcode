#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 循环遍历每圈的每条边
        vector<vector<int>> res(n, vector<int>(n));
        int row = 0;
        int col = 0;
        int cnt = 1;
        for (int len = n; len > 1; len -= 2) { // 由下面4条边的循环结束条件确定 len > 1
            for (int i = 0; i < len - 1; i++) {
                res[row][col++] = cnt++;
            }
            for (int i = 0; i < len - 1; i++) {
                res[row++][col] = cnt++;
            }
            for (int i = 0; i < len - 1; i++) {
                res[row][col--] = cnt++;
            }
            for (int i = 0; i < len - 1; i++) {
                res[row--][col] = cnt++;
            }
            row++;
            col++;
        }
        if (n % 2 == 1) {
            res[row][col] = cnt;
        }

        return res;
    }
};

int main() {
    Solution so = Solution();
    int n = 5;
    vector<vector<int>> matrix = so.generateMatrix(n);
    for (auto row : matrix) {
        for (auto i : row) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}