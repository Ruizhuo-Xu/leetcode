#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            // 考虑特殊情况
            return x;
        }
        int left = 2; // 排除0,1之后,从2开始
        int right = x - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            long square = (long) middle * middle; // 使用long防止上溢
            if (square > x) {
                right = middle - 1;
            } else if (square < x) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return right;
    }
};

int main() {
    Solution s = Solution();
    // int x = 2147395599;
    int x = 8;
    cout << "x=" << x << ",sqrt=" << s.mySqrt(x) << endl;
    return 0;
}