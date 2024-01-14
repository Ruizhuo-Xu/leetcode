#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int nextMaxCover = 0; // 下一步跳跃的最大覆盖范围(遍历当前这一步范围内的所有元素得到)
        int curMaxCover = 0; // 当前这一步的最大覆盖范围, 从0出发，所以初始值为0
        int res = 0; // 当前的步数
        for (int i = 0; i < nums.size(); i++) {
            if (curMaxCover >= nums.size() - 1) { // 当前这一步能到达末尾
                break;
            }
            nextMaxCover = max(nextMaxCover, i + nums[i]); // 更新下一步跳跃范围
            if (i == curMaxCover) { // 当前这一步的范围遍历完成，进入下一步
                curMaxCover = nextMaxCover;
                res++;
            }
        }
        return res; 
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution().jump(nums) << endl;
    return 0;
}