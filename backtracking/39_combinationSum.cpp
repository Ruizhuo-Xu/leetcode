#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }

    void backtracking(vector<int>& candidataes, int target, int sum, int startIndex) {
        if (sum == target) {
            res.push_back(nums);
            return ;
        }
        if (sum > target) {
            return ;
        }
        for (int i = startIndex; i < candidataes.size() && candidataes[i] + sum <= target; i++) {
            nums.push_back(candidataes[i]);
            backtracking(candidataes, target, sum + candidataes[i], i);
            nums.pop_back();
        }
    }
};

int main() {
    vector<int> candidates = {2,3,5};
    int target = 8;
    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}