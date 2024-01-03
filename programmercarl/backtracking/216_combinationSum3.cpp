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

    void backtracking(int k, int n, int startIndex, int sum) {
        // sum 记录的是上一层递归的和
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
            }
            return ;
        }
        // 两个剪枝: 对k这个约束的剪枝; 对n这个约束的剪枝
        for (int i = startIndex; (i <= 9 - (k - path.size()) + 1) && (i + sum <= n); i++) {
            path.push_back(i);
            backtracking(k, n, i + 1, sum + i);
            path.pop_back();
        }
    }
};

int main() {
    int k = 9, n = 45;
    vector<vector<int>> res = Solution().combinationSum3(k, n);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}