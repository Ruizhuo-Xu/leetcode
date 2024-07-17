#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][n - 1] > target) {
                right = mid - 1;
            } else if (matrix[mid][n - 1] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        if (left >= m) return false;  // target大于所有的数
        int row = left;
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] > target) {
                right = mid - 1;
            } else if (matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};