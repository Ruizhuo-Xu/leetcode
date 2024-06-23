#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int w = matrix.size();
        int loop = w / 2;
        int row = 0, col = 0;
        int endCol = w - 1;
        while (loop--) {
            for (int i = col; i < endCol; i++) {
                int temp = matrix[i][w - row - 1];
                swap(matrix[i][w - row - 1], matrix[row][i]);
                swap(temp, matrix[w - row - 1][w - i - 1]);
                swap(temp, matrix[w - i - 1][row]);
                swap(temp, matrix[row][i]);
            }
            row++; col++; endCol--;
        }
    }
};