#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return res;
    }

    void backtracking(int k, int n, int startIdx, int sum) {
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
            }
            return ;
        }
        for (int i = startIdx; i <= 9 && sum + i <= n && k - (int)path.size() <= 9 - i + 1; i++) {  // 两个剪枝：1.当前和已经大于目标值了 2.后续元素不够了
            path.push_back(i);
            backtracking(k, n, i + 1, sum + i);
            path.pop_back();
        }
    }
};