#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 时间复杂度O(2n),空间复杂度O(2n)
        vector<int> leftProdct(nums.size()), rightProduct(nums.size());
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            leftProdct[i] = product;
        }
        vector<int> res(nums.size());
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            rightProduct[i] = product;
            if (i == nums.size() - 1) {
                res[i] = leftProdct[i - 1];
            } else if (i == 0) {
                res[i] = rightProduct[i + 1];
            } else {
                res[i] = rightProduct[i + 1] * leftProdct[i - 1];
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> res = Solution().productExceptSelf(nums);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}