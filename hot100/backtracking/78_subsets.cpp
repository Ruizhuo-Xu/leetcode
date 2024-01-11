#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }

    void backtracking(vector<int>& nums, int startIndex) {
        // 时间复杂度: O(n * 2^n) 空间复杂度: O(n)
        res.push_back(path); // 收集所有的子集
        if (startIndex == nums.size()) {
            return ;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().subsets(nums);
    for (auto nums : res) {
        for (auto num : nums) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}