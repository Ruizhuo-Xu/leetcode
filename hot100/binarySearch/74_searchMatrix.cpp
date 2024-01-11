#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target) {
                int left = 0;
                int right = n;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] > target) right = mid;
                    else if (matrix[i][mid] < target) left = mid + 1;
                    else {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 11;
    cout << Solution().searchMatrix(matrix, target) << endl;
    return 0;
}