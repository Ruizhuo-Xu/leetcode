#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;  // 下面为了不溢出使用了除法，因此要对0做单独处理
        int left = 1; // 0单独处理了之后从1开始
        int right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (x / mid < mid) {
                right = mid - 1;
            } else if (x / mid > mid) {
                left = left + 1;
            } else {
                return mid;
            }
        }
        return right; // 如果不能整数开根号，那么根号值介于right-left之间
    }
};