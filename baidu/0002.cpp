#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> func(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
    int m = mat1.size();
    int n = mat1[0].size();
    int z = mat2[0].size();
    vector<vector<int>> res(m, vector<int>(z, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < z; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> mat1 = {{1, 2, 3}, {2, 3, 4}};
    vector<vector<int>> mat2 = {{1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> res = func(mat1, mat2);
    for (vector<int> row : res) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}