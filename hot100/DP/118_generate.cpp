#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            vector<int> row(i, 0);
            row[0] = 1;
            row[row.size() - 1] = 1; // 初始化首尾元素
            for (int j = 1; j < row.size() - 1; j++) { // 首尾外的元素
                row[j] = res[res.size() - 1][j - 1] + res[res.size() - 1][j]; // 递推公式
            }
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    int numRows = 5;
    vector<vector<int>> res = Solution().generate(numRows);
    for (auto nums : res) {
        for (int num : nums) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}