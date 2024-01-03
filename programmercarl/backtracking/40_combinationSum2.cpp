#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }

    void backtracking(vector<int> candidates, int target, int startIndex, int sum) {
        if (sum == target) {
            res.push_back(nums);
            return ;
        }
        if (sum > target) {
            return ;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) { // 和N数之和去重一样的逻辑
            // 注意是i > startIndex,而不是i > 0; 这样才能保证循环的第一轮能顺利进行
                continue;
            }
            nums.push_back(candidates[i]);
            backtracking(candidates, target, i + 1, sum + candidates[i]);
            nums.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = Solution().combinationSum2(candidates, target);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}