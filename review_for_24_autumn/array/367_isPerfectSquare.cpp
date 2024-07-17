#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long) mid * mid < num) {
                left = mid + 1;
            } else if ((long) mid * mid > num) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};