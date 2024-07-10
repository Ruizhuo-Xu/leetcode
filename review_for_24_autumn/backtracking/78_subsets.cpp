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

    void backtracking(vector<int>& nums, int startIdx) {
        // 子集问题：收集搜索树的每个节点,而组合问题则是收集搜索树的叶子节点
        res.push_back(path);
        for (int i = startIdx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};