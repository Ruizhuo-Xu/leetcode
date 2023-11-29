#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) {
            return true;
        }
        int left = 2;
        int right = num - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            long square = (long) middle * middle;
            if (square > num) {
                right = middle - 1;
            } else if (square < num) {
                left = middle + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    int num = 5;
    cout << "num=" << num << " " << "isPerfectSquare=" << s.isPerfectSquare(num) << endl;
    return 0;
}