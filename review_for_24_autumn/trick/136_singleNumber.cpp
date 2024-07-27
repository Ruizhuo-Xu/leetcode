#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 0异或任何数都为0
        // 相同的数异或为0
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};