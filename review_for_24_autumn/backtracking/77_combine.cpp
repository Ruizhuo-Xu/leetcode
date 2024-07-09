#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        // 时间复杂度O(n * 2^n)
        // 空间复杂度O(n)
        backtracking(n, k, 0);
        return res;
    }

    void backtracking(int n, int k, int startIdx) {
        if (path.size() == k) {
            res.push_back(path);
            return ;
        }
        for (int i = startIdx; i <= n && k - path.size() <= n - i + 1 ; i++) { // 剪枝：当前剩余未遍历的元素>=还缺少的元素
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};