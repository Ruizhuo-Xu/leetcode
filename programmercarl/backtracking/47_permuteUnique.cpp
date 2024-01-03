#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution_ {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 没有sort的版本,使用一个unordered_set来记录重复的元素
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

    void backtracking(vector<int>& nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return ;
        }
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || uset.find(nums[i]) != uset.end()) { // 相同元素的排列必然重复
                continue;
            }
            used[i] = true;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 使用sort后的去重,全排列问题sort不影响结果
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums , used);
        return res;
    }

    void backtracking(vector<int>& nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)) {
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
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}