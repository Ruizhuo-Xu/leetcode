#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        // 排列问题：每层都是从0开始搜索而不是startIndex；
        // 需要used数组记录path里都放了哪些元素了
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) { // 排列问题从0开始
            if (used[i]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().permute(nums);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}