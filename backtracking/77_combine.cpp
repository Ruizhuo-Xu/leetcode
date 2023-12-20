#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }

    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return ;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    int n = 4, k = 2;
    vector<vector<int>> res = Solution().combine(n, k);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}