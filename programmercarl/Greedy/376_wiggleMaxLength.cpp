#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1; // 默认序列末尾是一个峰值
        int prediff = 0; 
        int curdiff = 0;
        if (nums.size() <= 1) return res; // 只有一个元素的情况
        else { // 大于一个元素时, 需要对第一个元素是否是峰值做判断,因为下面的循环不包含第一个元素
            if (nums[0] == nums[1]) {
                prediff = 0;
            }
            else {
                res++;
                prediff = nums[1] - nums[0];
            }
        }
        for (int i = 1; i < nums.size() - 1; i++) { // 因为默认末尾是一个峰值,所以就只统计到末尾前一个
            curdiff = nums[i + 1] - nums[i];
            if ((prediff <= 0 && curdiff > 0) || (prediff >= 0 && curdiff < 0)) { // 找到峰值
                res++;
                prediff = curdiff;
            }
        }
        return res;
    }

};

int main() {
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    // vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int res = Solution().wiggleMaxLength(nums);
    cout << res;
}