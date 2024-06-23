#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int lp = 1;
        for (int i = 0; i < nums.size(); i++) {
            lp *= nums[i];
            res.push_back(lp);
        }
        int rp = 1;
        for (int i = nums.size() - 1; i >= 1; i--) {
            res[i] = res[i - 1] * rp;
            rp *= nums[i];
        }
        res[0] = rp;
        return res;
    }
};