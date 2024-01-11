#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 要剪枝必须要排序
        backtracking(candidates, 0, target, 0);
        return res;
    }

    void backtracking(vector<int>& candidates, int startIndex, int target, int sum) {
        if (sum == target) {
            res.push_back(path);
            return ;
        }
        if (sum > target) {
            return ;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, i, target, sum + candidates[i]); // 因为可以重复取，所以下一层递归从i开始
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    for (auto nums : res) {
        for (auto num : nums) {
            cout << num << ' ';
        }
        cout << endl;
    }
    return 0;
}