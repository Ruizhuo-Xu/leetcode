#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; // 0异或任何数都等于该数本身
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i]; // 任何数异或自身都等于0
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,2,1};
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}