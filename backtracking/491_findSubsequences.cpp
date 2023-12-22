#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // 不需要使用sort是因为题目规定了满足要求的子序列是递增的
        backtracking(nums, 0);
        return res;
    }

    void backtracking(vector<int> nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
                // 不满足递增或本层元素重复使用
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {4, 7, 6, 7};
    vector<vector<int>> res = Solution().findSubsequences(nums);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}