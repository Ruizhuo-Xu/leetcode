#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }

    void backtracking(vector<int>& candidates, int target, int startIdx) {
        if (target == 0) {
            res.push_back(path);
            return ;
        }
        for (int i = startIdx; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > startIdx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }
};