#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> digits;
        int temp = n;
        while (temp) { // 记录每个数字
            digits.push_back(temp % 10);
            temp /= 10;
        }
        int gap = 0;
        for (int i = digits.size() - 2; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) { // 数字不满足递增,如果数字是1324这种,不符合的数字是2,就直接-2*10-4*1-1
                //如果数字是332这种,不符合的数字是2,但是减去的-3*10-2*1-1
                while (i  < digits.size() - 2 && digits[i + 1] == digits[i + 2]) { // 例子：332
                    i++;
                }
                for (int j = i; j >= 0; j--) {
                    gap += digits[j] * pow(10, j);
                }
                return n - gap - 1;
            }
        }
        // 数字满足递增条件,则直接返回
        return n;
    }
};

int main() {
    cout << Solution().monotoneIncreasingDigits(332) << endl;
    return 0;
}