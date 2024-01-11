#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        // 时间复杂度 O(n*n!) 空间复杂度O(n)
        vector<bool> visited(nums.size(), false);
        backtracking(nums, visited);
        return res;
    }

    void backtracking(vector<int>& nums, vector<bool>& visited) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == true) continue;
            visited[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().permute(nums);
    for (auto nums : res) {
        for (auto num : nums) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}