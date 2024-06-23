#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = 0, col = 0;
        int h = matrix.size(), w = matrix[0].size();
        vector<int> res;
        while (h > 1 && w > 1) {
            for (int i = 0; i < w - 1; i++) {
                res.push_back(matrix[row][col++]);
            }
            for (int i = 0; i < h - 1; i++) {
                res.push_back(matrix[row++][col]);
            }
            for (int i = w - 1; i > 0; i--) {
                res.push_back(matrix[row][col--]);
            }
            for (int i = h - 1; i > 0; i--) {
                res.push_back(matrix[row--][col]);
            }
            row++; col++;
            w -= 2; h -= 2;
        }
        if (h == 1) {
            for (int i = 0; i < w; i++) {
                res.push_back(matrix[row][col++]);
            }
        } else if (w == 1) {
            for (int i = 0; i < h; i++) {
                res.push_back(matrix[row++][col]);
            }
        }
        return res;
    }
};