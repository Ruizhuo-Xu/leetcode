#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while (true) {
            int squareSum = getNumsSquareSum(n);
            mp[squareSum]++;
            if (mp[squareSum] > 1) {
                return false;
            }
            if (squareSum == 1) {
                return true;
            }
            n = squareSum;
        }
    }

    int getNumsSquareSum(int n) {
        int numsSquareSum = 0;
        while (n > 0) {
            int num = n % 10;
            numsSquareSum += num * num;
            n /= 10;
        }
        return numsSquareSum;
    }
};

int main() {
    int n = 19;
    cout << Solution().isHappy(n) << endl;
    return 0;
}
